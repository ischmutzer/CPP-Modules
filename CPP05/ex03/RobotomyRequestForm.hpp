#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class	RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& source);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& source);
		~RobotomyRequestForm();

		void	execute(const Bureaucrat& executor) const;
		AForm*	createRobotomyForm(std::string target);
		
	protected:
	private:
		std::string	_target;
};

#endif