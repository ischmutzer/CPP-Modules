#pragma once

#include <string>
#include "Form.hpp"

class	Intern {
	public:
		Intern();
		Intern(const Intern& source);
		Intern&	operator=(const Intern& source);
		~Intern();

		Form*	makeForm(std::string formName, std::string formTarget);
		static Form*	createPresidentialForm(std::string& target);
		static Form*	createRobotomyForm(std::string& target);
		static Form*	createShrubberyForm(std::string& target);

	protected:
	private:
};