#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("Default Target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source) : AForm(source) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& source) {
	if (this != &source) {
		AForm::operator=(source);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!getSigned())
		throw	UnsignedFormException();
	if (executor.getGrade() > getGradeToExecute())
		throw	GradeTooLowException();
	std::cout << "*drilling noises...*" <<  std::endl;
	if ((std::rand() % 2) == 0) {
		std::cout << _target << " has been successfully robotomized" << std::endl;
	}
	else {
	 	std::cout << "Robotomy failed" << std::endl;
	}
}

AForm*	RobotomyRequestForm::createRobotomyForm(std::string target) {
	return new RobotomyRequestForm(target);
}
