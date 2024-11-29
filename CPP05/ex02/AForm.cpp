#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

AForm::AForm(): _name("Default AForm"), _signed(false), _gradeToSign(1), _gradeToExec(1) {
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	std::cout << "AForm Parameterized constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& source): _name("Default Copy AForm"), _gradeToSign(source._gradeToSign), _gradeToExec(source._gradeToExec) {
	std::cout << "AForm Copy constructor called" << std::endl;
	*this = source;
}

AForm&	AForm::operator=(const AForm& source) {
	std::cout << "AForm Copy assignment operator called" << std::endl;
	if (this != &source) {
		_signed = source._signed;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm Default destructor called" << std::endl;
}

std::string	AForm::getName() const {
	return _name;
}

bool	AForm::getSigned() const {
	return _signed;
}

int	AForm::getGradeToSign() const {
	return _gradeToSign;
}

int	AForm::getGradeToExecute() const {
	return _gradeToExec;
}

void	AForm::beSigned(Bureaucrat& cog) {
	if (cog.getGrade() <= getGradeToSign())
		_signed = true;
	else
		throw GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::UnsignedFormException::what() const throw() {
	return "Form is unsigned!";
}

std::ostream&	operator<<(std::ostream& outStream, AForm& source) {
	outStream << source.getName() << " requires the Bureaucrat to have:\nGrade " << source.getGradeToSign() << " to sign\nGrade " << source.getGradeToExecute() << " to execute" << std::endl;
	return outStream;
}

