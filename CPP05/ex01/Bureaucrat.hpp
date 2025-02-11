#pragma once

#include <ostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& source);
		Bureaucrat&	operator=(const Bureaucrat& source);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form& form);
		//void		setGrade(int value);
		// void		incrementGradeByValue(int value);
		// void		decrementGradeByValue(int value);
		
		class GradeTooHigh : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLow : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	protected:
	private:
		const std::string	_name;
		int					_grade;
};
std::ostream&	operator<<(std::ostream& outStream, const Bureaucrat& Bureaucrat);
