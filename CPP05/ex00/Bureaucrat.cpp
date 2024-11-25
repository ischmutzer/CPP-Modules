#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <exception>
#include <string>

Bureaucrat::Bureaucrat(): _name("Default Bureaucrat"), _grade(1) {
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	std::cout << "Parameterized constructor called" << std::endl;
	if (_grade < 1)
		throw "Bureaucrat::GradeTooHigh"; // 1 is the highest grade, therefore 0 is too high
	else if (_grade > 150)
		throw "Bureaucrat::GradeTooLow"; 
}

Bureaucrat::Bureaucrat(const Bureaucrat& source) {
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& source) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source) {
		//_name is const so it can't be reassigned
		this->_grade = source.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Default destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

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

std::ostream&	operator<<(std::ostream& outStream, const Bureaucrat& Bureaucrat) {
	outStream << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return outStream;
}

const char*	Bureaucrat::GradeTooHigh::what() const throw() {
	return "Bureaucrat grade is too high!";
}

const char*	Bureaucrat::GradeTooLow::what() const throw() {
	return "Bureaucrat garde is too low!";
}
