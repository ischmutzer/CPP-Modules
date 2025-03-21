#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <stdexcept>

int main(int argc, char** argv) {
	try {
		if (argc == 2) {
			btc	calculator;
			calculator.launch(argv[1]);
			if (!argv[0])
			EXIT_SUCCESS;
		}
		// else if (argc == 1)
		// 	std::cerr << "Error: could not open file." << std::endl;
		// else
		// 	std::cerr << "Error: invalid arguments." << std::endl;
	} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	EXIT_FAILURE;

	/* try {
		if (argc != 2)
			throw std::invalid_argument("Error: could not open file."); //throw std::invalid_argument("Error: '" + std::to_string(argc - 1) + "' files")
		btc	calculator;
		calculator.launch(argv[1]);
		//calculator.processInput(argv[1]);
		EXIT_SUCCESS;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	EXIT_FAILURE; */
}
