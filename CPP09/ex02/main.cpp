#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

void	ok(std::vector<int> unsorted, const std::vector<int>& sorted) {
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---INPUT---" << std::endl;
	for (size_t i = 0; i < unsorted.size(); i++) {
		std::cout << unsorted[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::sort(unsorted.begin(), unsorted.end());

	std::cout << "---Supposed RESULT---" << std::endl;
	for (size_t i = 0; i < unsorted.size(); i++) {
		std::cout << unsorted[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---MY RESULT---" << std::endl;
	for (size_t i = 0; i < sorted.size(); i++) {
		std::cout << sorted[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	

	if (unsorted.size() != sorted.size())
		throw std::runtime_error("UNSUCCESSFUL: Sizes dont match!");
	for (size_t i = 0; i < unsorted.size(); i++) {
		if (unsorted[i] != sorted[i])
			throw std::runtime_error("UNSUCCESSFUL!");
	}
	std::cout << "SUCCESSFUL!" << std::endl;
}

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "ERROR: Missing arguments." << std::endl;
		return 1;
	}
	try {
		PmergeMe	instance;

		std::ostringstream oss;
		for (int i = 1; i < argc; ++i) {
			oss << argv[i] << " ";
		}
		instance.processInput(oss.str());
		
		Sorter<std::vector<int> >  v;
		std::vector<int> vect = instance.getVect();
		
		std::vector<int> unsorted = instance.getVect();

		//PRINTING VECT BEFORE SORT
		// std::cout << "\n---Vector Before Sorting---\n";
		// for (size_t i = 0; i < vect.size(); ++i) {
		// 	std::cout << vect[i] << " ";
		// }
		// std::cout << std::endl;

		//SORT
		v.sort(vect);

		//PRINTING VECT AFTER SORT
		// std::cout << "\n---Vector After Sorting---\n";
		// for (size_t i = 0; i < vect.size(); ++i) {
		// 	std::cout << vect[i] << " ";
		// }
		// std::cout << std::endl;

		ok(unsorted, vect);

		/* Sorter<std::deque<int> >	d;
		std::deque<int>				deque = instance.getDeque();

		//PRINTING DEQUE BEFORE SORT
		std::cout << "\n---Deque Before Sorting---\n";
		for (size_t i = 0; i < deque.size(); ++i) {
			std::cout << deque[i] << " ";
		}
		std::cout << std::endl;

		//SORT
		d.sort(deque);

		//PRINTING DEQUE AFTER SORT
		std::cout << "\n---Deque After Sorting---\n";
		for (size_t i = 0; i < deque.size(); ++i) {
			std::cout << deque[i] << " ";
		}
		std::cout << std::endl; */

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}


//posible way to call processInput() outside of a loop:

/* 	std::ostringstream oss;
	for (int i = 1; i < argc; ++i) {
		oss << argv[i] << " ";
	}
	instance.processInput(oss.str()); */