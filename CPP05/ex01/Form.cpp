#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

Form::Form(): _name("Default Form"), _signed(false), _gradeToSign(1), _gradeToExec(1) {
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	std::cout << "Form Parameterized constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& source): _name("Default Copy Form"), _gradeToSign(source._gradeToSign), _gradeToExec(source._gradeToExec) {
	std::cout << "Form Copy constructor called" << std::endl;
	*this = source;
}

Form&	Form::operator=(const Form& source) {
	std::cout << "Form Copy assignment operator called" << std::endl;
	if (this != &source) {
		_signed = source._signed;
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form Default destructor called" << std::endl;
}

std::string	Form::getName() const {
	return _name;
}

bool	Form::getSigned() {
	return _signed;
}

int	Form::getGradeToSign() const {
	return _gradeToSign;
}

int	Form::getGradeToExecute() const {
	return _gradeToExec;
}

void	Form::beSigned(Bureaucrat& cog) {
	if (cog.getGrade() <= getGradeToSign())
		_signed = true;
	else
		throw GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream&	operator<<(std::ostream& outStream, Form& source) {
	outStream << source.getName() << " requires the Bureaucrat to have:\nGrade " << source.getGradeToSign() << " to sign\nGrade " << source.getGradeToExecute() << " to execute" << std::endl;
	return outStream;
}
