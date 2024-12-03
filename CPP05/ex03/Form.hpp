#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

class	Form {
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& source);
		Form&	operator=(const Form& source);
		virtual ~Form();
		
		virtual void	execute(const Bureaucrat& executor) const = 0;
		std::string		getName() const;
		bool			getSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		void			beSigned(Bureaucrat& cog);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class UnsignedFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
	protected:
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
};
std::ostream&	operator<<(std::ostream& outStream, Form& source);

#endif