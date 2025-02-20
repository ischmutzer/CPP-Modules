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
