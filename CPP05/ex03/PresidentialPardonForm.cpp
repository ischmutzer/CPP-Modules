#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("Default Target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source) : AForm(source) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& source) {
	if (this != &source) {
		AForm::operator=(source);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!getSigned())
		throw	UnsignedFormException();
	if (executor.getGrade() > getGradeToExecute())
		throw	GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

AForm*	PresidentialPardonForm::createPresidentialForm(std::string target) {
	return new PresidentialPardonForm(target);
}
