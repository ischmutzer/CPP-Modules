#include "Bureaucrat.hpp"
#include <iostream>

int	main() {
	Bureaucrat	cog;
	Bureaucrat	cog2("Steve", 10);

	std::cout << "\n" << cog << std::endl;
	std::cout << cog2 << "\n" << std::endl;

	try {
		Bureaucrat cog3("Lili", 0);
	} catch (const std::exception& e) {
		std::cout << e.what() << "\n" << std::endl;
	}

	try {
		cog.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << "\n" << std::endl;
	}

	Bureaucrat	cog4("John", 150);
	try {
		cog4.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	//Copy constructor and copy assignment operator check
	/* Bureaucrat	copyCog(cog2);

	cog2.incrementGrade();
	std::cout << "\ncog2Grade has been incremented to: " << cog2 << "\n" << std::endl;

	copyCog.decrementGrade();
	std::cout << "copyCogGrade has been decremented to: " << copyCog << "\n" << std::endl;


	Bureaucrat	copy2("Karen", 2);
	std::cout << copy2 << "\n" << std::endl;
	copy2 = cog2;

	std::cout << "\n" << cog2 << std::endl;
	std::cout << copy2 << "\n" << std::endl; */

	return 0;
}