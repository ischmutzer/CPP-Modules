#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <ostream>
#include <exception>
#include <string>

Bureaucrat::Bureaucrat(): _name("Default Bureaucrat"), _grade(1) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	std::cout << "Bureaucrat Parameterized constructor called" << std::endl;
	if (_grade < 1)
		throw GradeTooHigh(); // 1 is the highest grade, therefore 0 is too high
	else if (_grade > 150)
		throw GradeTooLow(); 
}

Bureaucrat::Bureaucrat(const Bureaucrat& source): _name("Default Copy Bureaucrat") {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = source;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& source) {
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	if (this != &source) {
		//_name is const so it can't be reassigned
		this->_grade = source.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Default destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

// void	Bureaucrat::setGrade(int value) {
// 	_grade = value;
// 	if (value < 1)
// 		throw GradeTooHigh();
// 	else if (value > 150)
// 		throw GradeTooLow();
// }

void	Bureaucrat::incrementGrade() {
	_grade--;
	if (_grade < 1)
		throw GradeTooHigh();
}

void	Bureaucrat::decrementGrade() {
	_grade++;
	if (_grade > 150)
		throw GradeTooLow();
}

void	Bureaucrat::signForm(bool status, std::string formName) {
	if (status)
		std::cout << _name << " signed " << formName << std::endl;
	else
		std::cout << _name << " couldn't sign " << formName << " due to insufficient grade" << std::endl;
}

/* void	Bureaucrat::incrementGradeByValue(int value) {
	_grade -= value;
	if (_grade < 1)
		throw GradeTooHigh();
}

void	Bureaucrat::decrementGradeByValue(int value) {
	_grade += value;
	if (_grade > 150)
		throw GradeTooLow();
} */

std::ostream&	operator<<(std::ostream& outStream, const Bureaucrat& Bureaucrat) {
	outStream << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return outStream;
}

const char*	Bureaucrat::GradeTooHigh::what() const throw() {
	return "Bureaucrat grade is too high!";
}

const char*	Bureaucrat::GradeTooLow::what() const throw() {
	return "Bureaucrat grade is too low!";
}