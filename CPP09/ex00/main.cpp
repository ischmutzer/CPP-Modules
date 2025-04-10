#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <stdexcept>

int main(int argc, char** argv) {
	try {
		if (argc == 2) {
			btc	calculator;
			calculator.launch(argv[1]);
			return EXIT_SUCCESS;
		}
		else if (argc == 1)
		 	throw std::runtime_error("Error: no input file found.");
		else if (argc > 2)
		 	throw std::runtime_error("Error: too many arguments.");
	} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	return EXIT_FAILURE;
}
