#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class	Fixed {
	public:
		Fixed();
		Fixed(const int intVar);
		Fixed(const float floatVar);
		Fixed(const Fixed& source);
		~Fixed();
		Fixed&	operator=(const Fixed& source);

		bool	operator>(const Fixed& source) const;
		bool	operator<(const Fixed& source) const;
		bool	operator>=(const Fixed& source) const;
		bool	operator<=(const Fixed& source) const;
		bool	operator==(const Fixed& source) const;
		bool	operator!=(const Fixed& source) const;

		Fixed	operator+(const Fixed& source);
		Fixed	operator-(const Fixed& source);
		Fixed	operator*(const Fixed& source);
		Fixed	operator/(const Fixed& source);

		Fixed&	operator++(); //pre increment sytanx return a & and void parameter
		Fixed	operator++(int); //post increment syntax returns obj & dummy int parameter
		Fixed&	operator--();
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed&		min(Fixed& num1, Fixed& num2);
		static const Fixed&	min(const Fixed& num1, const Fixed& num2);
		static Fixed&		max(Fixed& num1, Fixed& num2);
		static const Fixed&	max(const Fixed& num1, const Fixed& num2);

	private:
		int					_fixedPoint;
		static const int	_fractionalBits;
};
//The operator<< overload is defined outside of the class definition because it is a non-member function. This allows it to take an ostream object as its first parameter and a Fixed object as its second parameter, enabling it to work with the standard output stream.
std::ostream&	operator<<(std::ostream& outStream, const Fixed& fixedPointValue);

#endif