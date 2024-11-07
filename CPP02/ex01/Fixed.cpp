#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPoint(0) {
	std::cout << "Deafult constructor called" << std::endl;
}

Fixed::Fixed(const int intVar) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = intVar << _fractionalBits; //Shifting an integer to the left by n bits is equivalent to multiplying the integer by (2^n). This is used to convert the integer to a fixed-point value.
}

//float needs to be multiplied by 2 to the power of the amount to shift and then casted into an int
Fixed::Fixed(const float floatVar) {
	std::cout << "Float constructor called" << std::endl;
	float	floatToConvert = floatVar;
	int	intToShift = floatToConvert * 256; // 2⁸ = 256
	_fixedPoint = intToShift << _fractionalBits; //directly shifting a flaot is not valid
}

Fixed::Fixed(const Fixed& source) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedPoint = source._fixedPoint;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& source) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &source)
		return *this;
	else
	 	this->_fixedPoint = source._fixedPoint;
	return *this;
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
	//a
	return 
}

int	Fixed::toInt(void) const {
	return _fixedPoint >> _fractionalBits;
}
