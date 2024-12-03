#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", 25, 5), _target("Default Target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source) : Form(source) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& source) {
	if (this != &source) {
		Form::operator=(source);
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
