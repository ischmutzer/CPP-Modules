#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class	PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& source);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& source);
		~PresidentialPardonForm();

		void	execute(const Bureaucrat& executor) const;
		AForm*	createPresidentialForm(std::string target);
		
	protected:
	private:
		std::string	_target;
};

#endif