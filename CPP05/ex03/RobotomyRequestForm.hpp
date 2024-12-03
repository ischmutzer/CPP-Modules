#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

class	RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& source);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& source);
		~RobotomyRequestForm();

		void	execute(const Bureaucrat& executor) const;
		
	protected:
	private:
		std::string	_target;
};

#endif