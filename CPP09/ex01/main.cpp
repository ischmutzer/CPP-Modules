#include "RPN.hpp"
#include <exception>
#include <iostream>

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: Invalid Argument Count" << std::endl;
		return 1;
	}
	try {
		RPN	calculator;
		calculator.processInput(argv[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}