#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
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

AForm*	makeForm(std::string& formName, std::string& formTarget) {
	std::string	forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	
	// AForm*	(*formConstructors[3])(const std::string) = {&RobotomyRequestForm::createRobotomyForm, &ShrubberyCreationForm::createShrubberyForm, &PresidentialPardonForm::createPresidentialForm};
	AForm*	(*formConstructors[3])(const std::string) = {
		[](const std::string& target) { return new RobotomyRequestForm(target);},
		[](const std::string& target){ return new ShrubberyCreationForm(target);},
		[](const std::string& target){ return new PresidentialPardonForm(target);}
	};
	
	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			return formConstructors[i](formTarget);
		}
	}
	std::cout << "ERROR: requested form does not exist!" << std::endl;
	return nullptr;
}