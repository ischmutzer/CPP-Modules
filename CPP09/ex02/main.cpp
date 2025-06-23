#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>

void	okVector(std::vector<int> unsorted, const std::vector<int>& sorted) {
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
	std::cout << "SUCCESSFUL! (VECTOR)" << std::endl;
}

void	okDeque(std::deque<int> unsorted, const std::deque<int>& sorted) {
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
	std::cout << "SUCCESSFUL! (DEQUE)" << std::endl;
}

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "ERROR: Missing arguments." << std::endl;
		return 1;
	}
	if (argc > 3001) {
		std::cerr << "Error: Too many arguments." << std::endl;
		return 1;
	}
	try {
		PmergeMe	instance;
		
		std::ostringstream oss;
		for (int i = 1; i < argc; ++i) {
			oss << argv[i] << " ";
		}
		instance.processInput(oss.str());
		//check
			Sorter<std::vector<int> >  v;
			std::vector<int> vect = instance.getVect();
			std::vector<int> unsorted = instance.getVect();
			v.sort(vect);
			okVector(unsorted, vect); //mine

			Sorter<std::deque<int> > d;
			std::deque<int> deque = instance.getDeque();
			std::deque<int> ogdeque = instance.getDeque();
			d.sort(deque);
			okDeque(ogdeque, deque);
		//check
		instance.sortPrintVector();
		instance.sortPrintDeque();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}




/* TO USE okVector() & okDeque():

Sorter<std::vector<int> >  v;
std::vector<int> vect = instance.getVect();
std::vector<int> unsorted = instance.getVect();
v.sort(vect);
ok(unsorted, vect); //mine

Sorter<std::deque<int> > d;
std::deque<int> deque = instance.getDeque();
std::deque<int> ogdeque = instance.getDeque();
d.sort(deque);
okDeque(ogdeque, deque);
*/

/* void	okVector(std::vector<int> unsorted, const std::vector<int>& sorted) {
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
	std::cout << "SUCCESSFUL! (VECTOR)" << std::endl;
} */

/* void	okDeque(std::deque<int> unsorted, const std::deque<int>& sorted) {
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
	std::cout << "SUCCESSFUL! (DEQUE)" << std::endl;
}
 */
