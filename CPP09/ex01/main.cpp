#include "RPN.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: Invalid Argument Count" << std::endl;
		return EXIT_FAILURE;
	}
	try {
		RPN	calculator;
		calculator.processInput(argv[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}


//Test Cases:

//OVERFLOW CHECK
//./RPN "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"

//VALID SIMPLE EXPRESSION
//./RPN "3 4 +"

//VALID MIXED OPERATIONS
//./RPN "5 1 2 + 4 * + 3 -"

//DIVISION BY ZERO
//./RPN "5 0 /"

//INSUFFICIENT OPERANDS FOR AN OPERATOR
//./RPN "3 +"

//EXTRA OPERANDS LEFT OVER
//./RPN "3 4"
