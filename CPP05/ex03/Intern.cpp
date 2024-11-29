#include "Intern.hpp"
#include "AForm.hpp"
#include <string>

Intern::Intern() {}

Intern::Intern(const Intern& source) {
	*this = source;
}

Intern&	Intern::operator=(const Intern& source) {
	if (this != &source) {
		//copy
	}
	return *this;
}

Intern::~Intern() {}

AForm*	makeForm(std::string& formName, std::string& formTarget) {
	std::string	forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	typedef void	(AForm)
	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			//a
		}
	}
	std::cout << "ERROR: requested form does not exist!" << std::endl;
}