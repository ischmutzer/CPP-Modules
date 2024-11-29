#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class	ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& source);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& source);
		~ShrubberyCreationForm();

		void		execute(const Bureaucrat& executor) const;
		std::string	generateTree() const;
		AForm*		createShrubberyForm(std::string target);

	protected:
	private:
		std::string	_target;
};

#endif