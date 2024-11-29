#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
	std::srand(std::time(0)); //seeding random number generator
/* 	try {
		ShrubberyCreationForm	a("gaia");
		Bureaucrat				ceo;

		a.beSigned(ceo);
		a.execute(ceo);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	} */
	/* try {
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
	try {
		Bureaucrat	janet("Janet", 50);
		ShrubberyCreationForm	home("home");

		home.beSigned(janet);
		janet.executeForm(home);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
/*	Bureaucrat	janet("Janet", 50);
	ShrubberyCreationForm	home("home");

	home.beSigned(janet);
	janet.executeForm(home);
	return 0;*/
}
