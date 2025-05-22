#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "ERROR: Missing arguments." << std::endl;
		return 1;
	}
	try {
		PmergeMe	instance;
		
		for (int i = 1; i < argc; i++) {
			instance.processInput(argv[i]);
		}
		Sorter<std::vector<int> >  ex;

		std::vector<int> vect = instance.getVect();
		ex.sort(vect);
		//instance.mergeInsert();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}