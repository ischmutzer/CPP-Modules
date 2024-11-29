#pragma once

#include <string>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern {
	public:
		Intern();
		Intern(const Intern& source);
		Intern&	operator=(const Intern& source);
		~Intern();

		AForm*	makeForm(std::string& formName, std::string& formTarget);

	protected:
	private:
};