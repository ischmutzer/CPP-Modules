#include "Array.hpp"
#include <exception>
#include <iostream>

int	main() {
	try {
	Array<int>	empty;
	printArray(empty, "Created empty array");

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
	//test[0] = "test1"; //-> const obj can be read but not written
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

	// Edge case: Access first and last element
	Array<int> edgeCaseArray(2);
	edgeCaseArray[0] = 1;
	edgeCaseArray[1] = 99;
	std::cout << "First element: " << edgeCaseArray[0] << std::endl;
	std::cout << "Last element: " << edgeCaseArray[1] << std::endl;

	// Edge case: Out-of-bounds access (should throw)
	try {
	    std::cout << edgeCaseArray[2] << std::endl; // Out of bounds
	} catch (std::exception& e) {
	    std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// Edge case: Copying array of different sizes
	Array<int> smallArray(1);
	smallArray[0] = 5;

	Array<int> largerArray(5);
	largerArray = smallArray;
	printArray(largerArray, "Larger array after being assigned a smaller one");

	Array<int>	big(4);
	big[0] = 1;
	big[1] = 2;
	big[2] = 2;
	big[3] = 4;
	smallArray = big;
	printArray(smallArray, "Smaller array into bigger array");

	// Edge case: Copying an empty array
	Array<int> emptyArray;
	Array<int> copiedEmpty(emptyArray);
	printArray(copiedEmpty, "Copied empty array");

	return 0;
}
