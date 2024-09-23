#include <iostream>
#include <string>



int	main() {
	std::string		string = "HI THIS IS BRAIN";

	//PTR
	//a ptr holds the memory address of the string it points to and can be used to access the string's value
	
	//&strPtr gives me the memory address of strPtr
	//strPtr gives me the memory address strPtr is pointing to
	//*strPtr gives me the value stored in the memory address strPtr is pointing to
	std::string*	strPtr = &string;

	//REF
	//a ref behaves like an alias to the original variable and accesses the same memory.
	std::string&	strRef = string;

	std::cout << "\n" << "The memory address of the string variable is: " << &string << std::endl;
	std::cout << "The memory address of the string pointer is: " << strPtr << std::endl;
	std::cout << "The memory address of the string reference is: " << &strRef << std::endl;

	std::cout << "\n" << "The value stored in the string is: " << string << std::endl;
	std::cout << "The value stored in the address pointed by strPtr is: " << *strPtr << std::endl;
	std::cout << "The value stored in strRef is: " << strRef << std::endl;
}