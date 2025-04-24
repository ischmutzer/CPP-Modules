#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {

	//TESTING WITH VECTOR CONTAINER
	std::vector<int>	vec1(5);
	vec1.push_back(17);
	vec1.push_back(5);
	vec1.push_back(1);
	vec1.push_back(0);
	vec1.push_back(-12);

	try {
		std::vector<int>::const_iterator vecIt = easyFind(vec1, 17);
		std::cout << "Found occurrence: " << *vecIt << " in vector\n";

		std::vector<int>::const_iterator nonExistVecIt = easyFind(vec1, 10);
		std::cout << "Found: " << *nonExistVecIt << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	//TESTING WITH LIST CONTAINER
	std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    try {
        // Test finding an existing value in list
        std::list<int>::const_iterator listIt = easyFind(lst, 30);
        std::cout << "Found occurrence: " << *listIt << " in list\n";

        // Test finding a non-existent value in list (will throw exception)
        std::list<int>::const_iterator nonExistListIt = easyFind(lst, 60);
		std::cout << "Found: " << *nonExistListIt << "\n";
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	return 0;
}
