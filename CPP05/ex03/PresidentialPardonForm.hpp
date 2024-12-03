#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

class	PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& source);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& source);
		~PresidentialPardonForm();

		void	execute(const Bureaucrat& executor) const;
		
	protected:
	private:
		std::string	_target;
};

#endif