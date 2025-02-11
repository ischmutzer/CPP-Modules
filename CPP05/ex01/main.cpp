#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main() {
	Bureaucrat	cog("STEVE", 3);
	Form		form("2025 Budget Redistribution", 2, 2);

	std::cout << "\n" << form << std::endl;
	std::cout << cog << "\n" << std::endl;

	try {
		form.beSigned(cog);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	cog.signForm(form);
	std::cout << std::endl;

	cog.incrementGrade();
	form.beSigned(cog);
	cog.signForm(form);
	std::cout << std::endl;

	try {
		Form	form2("invalid", 1, 152);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}