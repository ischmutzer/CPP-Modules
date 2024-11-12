#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPoint(0) {
	std::cout << "Deafult constructor called" << std::endl;
}

Fixed::Fixed(const int intVar) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = intVar << _fractionalBits; //Shifting an integer to the left by n bits is equivalent to multiplying the integer by (2^n). This is used to convert the integer to a fixed-point value.
}

//float needs to be multiplied by 2 to the power of the amount to shift and then casted into an int
/* Fixed::Fixed(const float floatVar) {
	std::cout << "Float constructor called" << std::endl;
	float	floatToConvert = floatVar;
	int	intToShift = floatToConvert * 256; // 2⁸ = 256
	_fixedPoint = intToShift << _fractionalBits; //directly shifting a flaot is not valid
} */

//float needs to be multiplied by 2 to the power of the amount to shift and then casted into an int
Fixed::Fixed(const float floatVar) {
	std::cout << "Float constructor called" << std::endl;
    _fixedPoint = roundf(floatVar * (1 << _fractionalBits)); //(1 << _fractionalBits) = 2^8 = 256
}

Fixed::Fixed(const Fixed& source) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedPoint = source._fixedPoint;
	//*this = source; -> this would call the copy assignment operator
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

//modified to be more encapsulated and adopt better practice
//will print double message
Fixed&	Fixed::operator=(const Fixed& source) {
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &source)
		this->_fixedPoint = source.getRawBits();
	return *this;

//original version:
	/* if (this == &source)
		return *this;
	else
	 	this->_fixedPoint = source._fixedPoint;
	return *this; */
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}


void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPoint = raw;
}

float	Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPoint) / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return _fixedPoint >> _fractionalBits;
}

std::ostream&	operator<<(std::ostream& outStream, const Fixed& fixedPointValue) {
	outStream << fixedPointValue.toFloat();
	return outStream;
}


//NOTES:

//Key Concepts:

//Fixed-point Numbers
//-> these are numbers where a fixed numver of digits are used for the fractional part.

//Floating-point Numbers
//-> these are numbers that can represent fractions and very large or very small numbers
//using a format that includes a base (or mantissa) and an exponent.

//Fixed-point arithmetic is a method of representing numbers that
//have a fixed number of digits after the decimal point. This is 
//in contrast to floating-point arithmetic, which allows for a variable
//number of digits after the decimal point.