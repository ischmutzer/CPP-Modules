#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main() {
	try {
		ShrubberyCreationForm	a("gaia");
		Bureaucrat				ceo;

		a.beSigned(ceo);
		a.execute(ceo);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
/* 	try {
		Bureaucrat	ceo;
		RobotomyRequestForm	b("steve");

		b.beSigned(ceo);
		b.execute(ceo);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	} */
/* 	try {
		Bureaucrat fakeCeo("David", 130);
		PresidentialPardonForm	c("Evil janitor");

		c.beSigned(fakeCeo);
		c.execute(fakeCeo);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	} */
	return 0;
}
