#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "ERROR: Not enough arguments." << std::endl;
		return 1;
	}
	try {
		for (int i = 1; i < argc; i++) {
			//check that the value is a positive integer and store it in _array
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}