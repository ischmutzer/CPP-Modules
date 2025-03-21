#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

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

	//read line by line, parse it at "," and store key and value in map
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
			//check key and value format and convert value to double
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