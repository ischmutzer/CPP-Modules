#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <ostream>
#include <string>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& source);
		Bureaucrat&	operator=(const Bureaucrat& source);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade(); //should it be only incremented by a fixed amount always or should I accept a value to increment?
		void		decrementGrade();
		
		const char*	GradeTooHigh(); //should this be a class of its own and inherit from the exception class?
		const char*	GradeTooLow(); //should this be a class of its own and inherit from the exception class?

	protected:
	private:
		const std::string	_name;
		int					_grade;
};
std::ostream&	operator<<(std::ostream& outStream, const Bureaucrat& Bureaucrat);

#endif