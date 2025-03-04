#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <stdexcept>

int main(int argc, char** argv) {
	try {
		if (argc != 2)
			throw std::invalid_argument("Error: could not open file."); //throw std::invalid_argument("Error: '" + std::to_string(argc - 1) + "' files")
		btc	calculator;
		calculator.launch(argv[1]);
		//calculator.processInput(argv[1]);
		EXIT_SUCCESS;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	EXIT_FAILURE;
}
