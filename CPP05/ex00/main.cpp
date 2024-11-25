#include "Bureaucrat.hpp"
#include <iostream>

int	main() {
	Bureaucrat	cog;
	Bureaucrat	cog2("Steve", 10);

	std::cout << "\n" << cog << std::endl;
	std::cout << cog2 << "\n" << std::endl;

	try {
		Bureaucrat cog3("Lili", 0);
	} catch (const char* exception) {
		std::cout << exception << std::endl;
	}

	try {
		cog.incrementGrade();
	} catch (const char* e) {
		std::cout << e << std::endl;
	}

	Bureaucrat	cog4("John", 150);
	try {
		cog4.decrementGrade();
	} catch (const char* e) {
		std::cout << e << std::endl; 
	}

	std::cout << std::endl;

	return 0;
}