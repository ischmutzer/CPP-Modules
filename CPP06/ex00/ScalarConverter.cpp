#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& source) {
	*this = source;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter& source) {
	if (this != &source) {
		//copy
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::intCheck(std::string& input) {
	std::stringstream	ss(input);
	
	int	value;
	if (!(ss >> value))
		return false;

	char	leftover;
	if (ss >> leftover)
		return false;
	ss >> intVal;
	return true;
}

bool	ScalarConverter::floatCheck(std::string input) {
	if (input == ".f")
		return true; //convert
	int	i = 0;
	while (i < input.length())
}

void	ScalarConverter::checkInput(std::string& input) {
	if (intCheck(input))
		//CONVERT VAL & store
}

void	ScalarConverter::convert(std::string input) {
	//do
	checkInput(input);
}

// You have to first detect the type of the literal passed as parameter, convert it from
// string to its actual type, then convert it explicitly to the three other data types. Lastly,
// display the results as shown below