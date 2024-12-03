#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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

Form*	Intern::createPresidentialForm(std::string& target) {
	return new PresidentialPardonForm(target);
}

Form*	Intern::createRobotomyForm(std::string& target) {
	return new RobotomyRequestForm(target);
}

Form*	Intern::createShrubberyForm(std::string& target) {
	return new ShrubberyCreationForm(target);
}

Form*	Intern::makeForm(std::string formName, std::string formTarget) {
	std::string	forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	
	typedef Form*	(*formConstructor)(std::string&);
	formConstructor	formConstructors[3] = {
		&Intern::createRobotomyForm,
		&Intern::createShrubberyForm,
		&Intern::createPresidentialForm,
	};

	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			return formConstructors[i](formTarget);
		}
	}
	std::cout << "ERROR: requested form does not exist!" << std::endl;
	return NULL;
}