#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <ctime>

btc::btc() {}

btc::btc(const btc& source) { *this = source; }

btc&	btc::operator=(const btc& source) {
	if (this != &source) {
		_btcPrices = source._btcPrices;
		_value = source._value;
	}
	return *this;
}

btc::~btc() {}

std::string	btc::trim(const std::string& str) {
	std::string::size_type	start = 0;
	while (start < str.size() && std::isspace(str[start])) {
		start++;
	}
	std::string::size_type	end = str.size();
	while (end > start && std::isspace(str[end - 1])) {
		end--;
	}
	return str.substr(start, end - start);
}

bool	btc::dateValidation(const std::string& key) {
	if (key.size() != 10 || key[4] != '-' || key[7] != '-')
		return false;
	int	year, month, day;
	if (sscanf(key.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
		return false;

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	bool leap = (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));

	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (leap && month == 2) {
		if (day > 29) return false;
	} else {
		if (day > daysInMonth[month - 1])
		return false;
	}
	
	std::time_t	now = std::time(0);
	struct tm*	localTime = localtime(&now);
	
	if (year > localTime->tm_year + 1900)
		return false;
	if (year == localTime->tm_year + 1900) {
		if (month > localTime->tm_mon + 1)
			return false;
		if (month == localTime->tm_mon + 1 && day > localTime->tm_mday)
			return false;
	}
	return true;
}

bool	btc::inputDateValidation(const std::string& key) {
	if (key.size() != 11 || key[4] != '-' || key[7] != '-')
		return false;

	int	year, month, day;
	if (sscanf(key.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
		return false;

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	bool leap = (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));

	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (leap && month == 2) {
		if (day > 29) return false;
	} else {
		if (day > daysInMonth[month - 1])
		return false;
	}
	
	/* std::time_t	now = std::time(0);
	struct tm*	localTime = localtime(&now);
	
	if (year > localTime->tm_year + 1900)
		return false;
	if (year == localTime->tm_year + 1900) {
		if (month > localTime->tm_mon + 1)
			return false;
		if (month == localTime->tm_mon + 1 && day > localTime->tm_mday)
			return false;
	} */
	return true;
}

bool	btc::dbNumberValidation(const std::string& key, const std::string& price) {
	if (price.empty())
		return false ;

	std::istringstream	sStr(price);
	double	num;

	if (!(sStr >> num))
		return false;
	
	char	extra;
	if (sStr >> extra)
		return false;
		
	if (num < 0)
		return false;
	
	_btcPrices[key] = num;
	return true;
	
}

bool	btc::inNumberValidation(const std::string& val) {
	if (val.empty())
		return false;
	
	for (size_t i = 0; isspace(val[i]);) {
		i++;
		if (i > 1)
			return false;
	}

	std::istringstream	value(val);
	double				num;

	if (!(value >> num))
		return false;

	char extra;
	if (value >> extra)
		return false;
	
	if (num < 0.0 || num > 1000.0)
		return false;

	_value = num;
	return true;
}

double	btc::getExchangeRate(const std::string& key) {
	if (_btcPrices.empty()) {
		throw std::runtime_error("Error: No exchange rate data available.");
	}
	std::map<std::string, double>::iterator	it = _btcPrices.lower_bound(key);
	if (it != _btcPrices.end() && it->first == key) {
		//_date = it->first;
		return it->second;
	}
	if (it != _btcPrices.begin()) {
		--it;
		//_date = it->first;
		return it->second;
	}
	else {
		//_date = it->first;
		return it->second;
	}
	//return _btcPrices.begin()->second;
}

void	btc::calculateRateXValue(double rate, const std::string& key) {
	double	total = rate * _value;
	std::cout << key << " => " << _value << " = " << total << std::endl;
}

void	btc::processFile(const std::string& file) {
	std::ifstream	inputFile(file.c_str());
	if (!inputFile.is_open())
		throw	std::runtime_error("Error: Could not open input file.");

	if (inputFile.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: Input file is emtpy.");
	
	std::string	line;
	if (std::getline(inputFile, line)) {
		if (line != "date | value")
			throw std::runtime_error("Error: Invalid header in input file.");
	}
	while (std::getline(inputFile, line)) {
		if (line.empty())
			continue;
		if (line[0] == ' ')
			throw std::runtime_error("Error: Leading space identified.");
		std::string			trimmedLine = trim(line);
		std::istringstream	iss(trimmedLine);
		std::string			key, value;
		if (std::getline(iss, key, '|') && std::getline(iss, value)) {
			if (!inputDateValidation(key)) {
				std::cerr << "Error: Invalid date in input file." << std::endl;
				continue;
			}
			if (!inNumberValidation(value)) {
				std::cerr << "Error: Invalid value in input file." << std::endl;
				continue;
			}
		}
		else {
			std::cerr << "Error: getline() failed while processing the input file." << std::endl;
			continue;
		}
		calculateRateXValue(getExchangeRate(key), key);
	}
	inputFile.close();
}

void	btc::processDatabase() {
	std::ifstream	database("data.csv");
	if (!database.is_open())
		throw std::runtime_error("Error: Could not open database file.");
	
	if (database.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: Database file is empty.");

	std::string	line;
	if (std::getline(database, line)) {
		if (line != "date,exchange_rate")
			throw std::runtime_error("Error: Invalid header in database.");
	}
	while (std::getline(database, line)) {
		if (line.empty())
			continue ;

		std::string			trimmedLine = trim(line);
		std::istringstream	iss(trimmedLine);
		std::string			key, value;

		if (std::getline(iss, key, ',') && getline(iss, value)) {
			//std::cout << "\nkey = " << key << " \n" << "value = " << value << std::endl;
			if (!dateValidation(key)) {
				std::cerr << "Error: Invalid date" << std::endl;
				continue ;
			}
			if (!dbNumberValidation(key, value)) {
				std::cerr << "Error: Invalid price in database." << std::endl;
				continue;
			}
		}
		else
			throw std::runtime_error("Error: getline() failed while processing database.");
	}
	database.close();
}

void	btc::launch(const std::string& inputFile) {
	try  {
		processDatabase();
		/* std::map<std::string, double>::iterator it;
		for (it = _btcPrices.begin(); it != _btcPrices.end(); it++) {
			std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
		} */
		processFile(inputFile);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;	}
}



//NOTES

//->ifstream is a class derived from isstream, when an obj is instantiated
//and no mode is specified (only file path), the constructor defaults to ios::in (read-only)
//this open can fail silently so it needs checking


//when extracting a double using istringstream it does not lose precision but std::cout truncates the output