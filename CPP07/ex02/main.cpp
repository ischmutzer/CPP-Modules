#include "Array.hpp"
#include <exception>
#include <iostream>

int	main() {
	try {
	Array<int>	empty;
	std::cout << "empty size = " << empty.size() << "\n\n";

	Array<int> intArray(5);
	intArray[0] = 7;
	intArray[1] = 6;
	intArray[2] = 5;
	intArray[3] = 4 * 2;
	intArray[4] = 3;
	intArray[0] = 1;
	// intArray[-1] = 0;
	// intArray[7] = 7; -> will throw exception
	printArray(intArray, "int arr");

	const Array<std::string>	test(2);
	std::cout << "\ntest size = " << test.size() << "\n";
	std::cout << "test[0] = " << test[0] << "\n";
	//test[0] = "test1"; -> const obj can be read but not written
	std::cout << "\n";

	Array<int>	copy(5);
	copy = intArray;
	printArray(copy, "copy assignment operator array");
	printArray(intArray, "intArray after");
	std::cout << "\n";

	Array<int>	copyConstructor(copy);
	printArray(copyConstructor, "copy constructor array");
	printArray(copy, "copy array after");
	std::cout << "\n";

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
