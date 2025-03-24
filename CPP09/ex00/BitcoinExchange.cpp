#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <ctime>

btc::btc() {}

btc::btc(const btc& source) { *this = source; }

btc&	btc::operator=(const btc& source) {
	if (this != &source) {}
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

	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > daysInMonth[month - 1])
		return false;
	
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

double	btc::numberValidation(const std::string& value) {
	std::istringstream	iss(value);
	double				convertedValue;

	if (!(iss >> convertedValue))
		return -1.0;

	std::string	rest;
	iss >> rest;
	if (!rest.empty())
		return -1.0;
	
}

void	btc::processFile(const std::string& file) {
	std::cout << "Current dir: " << system("pwd");

	std::ifstream	inputFile(file.c_str());
	if (!inputFile.is_open())
		throw	std::runtime_error("Error: could not open file.");
	//check file
	
	inputFile.close();
}

void	btc::processDatabase() {
	std::ifstream	database("data.csv");
	if (!database.is_open())
		//std::cerr << "Error: could not open file" << std::endl; return;
		throw std::runtime_error("Error: Could not open database file");
	
	if (database.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: Database file is empty"); //TO-DO: exit program

	std::string	line;
	while (std::getline(database, line)) {
		if (line.empty())
			continue ;

		//std::cout << "Normal line:" << line  << "\nLine size length:" << line.length() << std::endl;
		std::string	cleanLine = trim(line);
		//std::cout << "Clean Line:" << cleanLine << "\nClean line lenght" << cleanLine.length() << std::endl;
		
		std::istringstream	iss(cleanLine);
		std::string	key, value;
		if (std::getline(iss, key, ',') && getline(iss, value)) {
			std::cout << "\nkey = " << key << " \n" << "value = " << value << std::endl;
			if (!dateValidation(key)) {
				std::cerr << "Error: Invalid date: " << key << std::endl;
				continue ;
			}
			//check value format and convert value to double
			
			//_btcPrices[key] = value;

		}
		else
			throw std::runtime_error("Error: getline() failed while processing database.");
	}
	database.close();
}

void	btc::launch(const std::string& inputFile) {
	try  {
		processDatabase();
		processFile(inputFile);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;	
	}
	//check database
	//check input
	// checkFile("data.csv");
	// checkFile(inputFile);
}

//NOTES

//->ifstream is a class derived from isstream, when an obj is instantiated
//and no mode is specified (only file path), the constructor defaults to ios::in (read-only)
//this open can fail silently so it needs checking