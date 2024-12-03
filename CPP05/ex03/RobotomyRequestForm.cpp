#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", 72, 45), _target("Default Target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source) : Form(source) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& source) {
	if (this != &source) {
		Form::operator=(source);
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
