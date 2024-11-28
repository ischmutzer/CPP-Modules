#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

class	AForm {
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm& source);
		AForm&	operator=(const AForm& source);
		~AForm();
		
		virtual void execute(const Bureaucrat& executor) const = 0; //to make AForm abstract
		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat& cog);

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
std::ostream&	operator<<(std::ostream& outStream, AForm& source);

#endif