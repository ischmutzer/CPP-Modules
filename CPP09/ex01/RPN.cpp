#include "RPN.hpp"
#include <string>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN& source) { *this = source; }

RPN&	RPN::operator=(const RPN& source) {
	if (this != &source) {}
	return *this;
}

RPN::~RPN() {}

void	RPN::checkForInvalidChar(std::string input) {
	for (size_t i = 0; i < input.size(); i++) {
		if (input[i] == ' ')
			continue ;
		else if (input[i] >= '0' && input[i] <= '9')
			continue ;
		else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
			continue ;
		else
		 	throw std::invalid_argument("Error: invalid character in input");
	}
	std::string	cleanString;
	for (size_t i = 0; i < input.size(); i++) {
		if (input[i] != ' ')
			cleanString += input[i];
	}
	cleanInput = cleanString;
	std::cout << cleanString << std::endl;
}

void	RPN::tokenization(std::string& input) {
	for (size_t i = 0; i < input.size(); i++) {
		if (input[i] >= '0' && input[i] <= '9') {
			int digit = input[i] - '0';
			numbers.push(digit);
		}
		else
			operators.push(input[i]);
	}
}

void	RPN::launch(std::string input) {
	checkForInvalidChar(input);
	tokenization(cleanInput);
}