#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>
#include <exception>

int	main() {
	try {
		Intern	alex;

		alex.makeForm("", "house");
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	Intern	alex;
	Form* a = alex.makeForm("presidential pardon", "villa");
	Bureaucrat steve("steve", 1);
	a->beSigned(steve);
	a->execute(steve);
}