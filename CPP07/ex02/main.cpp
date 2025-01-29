#include "Array.hpp"
#include <iostream>

int	main() {
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray.changeValueElement(5, 4);
	}
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
	return 0;
}
