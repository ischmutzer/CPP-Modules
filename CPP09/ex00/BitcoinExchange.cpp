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

void	btc::processInput(const std::string& file) {
	std::ifstream	inputFile(file.c_str());

	if (!inputFile.is_open())
		throw	std::runtime_error("Error: could not open file.");
	//process file
	
	inputFile.close();
}
