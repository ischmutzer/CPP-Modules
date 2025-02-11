#pragma once

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& source);
		Form&	operator=(const Form& source);
		~Form();

		std::string	getName() const;
		bool		getSigned();
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(const Bureaucrat& cog);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
	protected:
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec; //a const grade require to execute it
};
std::ostream&	operator<<(std::ostream& outStream, Form& source);
