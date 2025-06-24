#include "RPN.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <climits>

RPN::RPN() {}

RPN::RPN(const RPN& source) { *this = source; }

RPN&	RPN::operator=(const RPN& source) {
	if (this != &source) {
		numbers = source.numbers;
		cleanInput = source.cleanInput;
	}
	return *this;
}

RPN::~RPN() {}

bool	RPN::isOperator(char c) const {
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

void	RPN::validateToken(const std::string& token) {
	if (token.length() != 1 || (!isdigit(token[0]) && !isOperator(token[0]))) {
		throw std::invalid_argument("Error: Invalid token '" + token + "'");
	}
}

void	RPN::tokenization(const std::string& expression) {
	char c = expression[0];
	if (isdigit(c)) {
		numbers.push(c - '0');
	}
	else {
		if (numbers.size() < 2)
			throw std::logic_error("Error: Insufficient operands.");
		long long b = numbers.top(); numbers.pop();			//top return ref to top element and pop removes top element, returning void
		long long a = numbers.top(); numbers.pop();
		switch (c) {
				case '+':
					numbers.push(a + b);
					break;
				case '-':
					numbers.push(a - b);
					break;
				case '*':
					numbers.push(a * b);
					break;
				case '/':
					if (b == 0) throw std::logic_error("Error: Division by zero");
					numbers.push(a / b);
					break;
				default: throw std::invalid_argument("Error: Unknown operator");
			}
	}
}

void	RPN::printResult() {
	if (numbers.empty())
		throw std::runtime_error("Error: Stack is empty");
	long long result = numbers.top();
	if (result > INT_MAX)
		throw std::overflow_error("Error: Result is bigger than int max");
	else if (result < INT_MIN)
		throw std::overflow_error("Error: Result is smaller than int min");
	std::cout << result << std::endl;
}

void	RPN::processInput(std::string input) {
	std::istringstream	expression(input);
	std::string			token;

	while (expression >> token) {
		validateToken(token);
		tokenization(token);
	}
	if (numbers.size() != 1)
		throw std::runtime_error("Error: Invalid expression.");
	printResult();
}
