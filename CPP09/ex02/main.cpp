#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>

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
		instance.sortPrintVector();
		instance.sortPrintDeque();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}




/* TO USE ok():
Sorter<std::vector<int> >  v;
std::vector<int> vect = instance.getVect();
std::vector<int> unsorted = instance.getVect();
v.sort(vect);
ok(unsorted, vect); //mine
*/

/* void	ok(std::vector<int> unsorted, const std::vector<int>& sorted) {
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
} */