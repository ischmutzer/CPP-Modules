#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>

btc::btc() {}

btc::btc(const btc& source) { *this = source; }

btc&	btc::operator=(const btc& source) {
	if (this != &source) {}
	return *this;
}

btc::~btc() {}

void	btc::processFile(const std::string& file) {
	std::cout << "Current dir: " << system("pwd");

	std::ifstream	inputFile(file.c_str());
	if (!inputFile.is_open())
		throw	std::runtime_error("Error: could not open file.");
	//check file
	
	inputFile.close();
}

void	btc::processDatabase() {
	std::ifstream	inFile("data.csv");
	if (!inFile.is_open())
		throw std::runtime_error("Error: Could not open database file");
	//read line by line, parse it at "," and store key and value in map
	inFile.close();
}

void	btc::launch(const std::string& inputFile) {
	//check database
	//check input
	// checkFile("data.csv");
	// checkFile(inputFile);
}

//NOTES

//->ifstream is a class derived from isstream, when an obj is instantiated
//and no mode is specified (only file path), the constructor defaults to ios::in (read-only)
//this open can fail silently so it needs checking