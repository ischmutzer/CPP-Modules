#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source) : AForm(source) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source) {
	if (this != &source) {
		AForm::operator=(source);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string	ShrubberyCreationForm::generateTree() const {
	return 
	 	"        ^        \n"
        "       ^^^       \n"
        "      ^^^^^      \n"
        "     ^^^^^^^     \n"
        "    ^^^^^^^^^    \n"
        "       |||       \n"
        "       |||       \n";
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getSigned())
		throw UnsignedFormException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	//create target_shrubbery
	std::string	fileName = _target + "_shrubbery";
	std::ofstream	file(fileName.c_str());
	if (!file) {
		return ;
	}
	file << generateTree();
	file.close();
}