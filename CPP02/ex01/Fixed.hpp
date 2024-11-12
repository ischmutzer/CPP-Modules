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
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_fixedPoint;
		static const int	_fractionalBits;
};
//The operator<< overload is defined outside of the class definition because it is a non-member function. This allows it to take an ostream object as its first parameter and a Fixed object as its second parameter, enabling it to work with the standard output stream.
std::ostream&	operator<<(std::ostream& outStream, const Fixed& fixedPointValue);

#endif