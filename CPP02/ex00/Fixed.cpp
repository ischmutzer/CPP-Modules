#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_fractionalBits = 8;

//since _fractionalBits is a const int, the value cannot be changed after initializing it
//therefore we need to use the initilaizer list to initialize its memeber before the
//constructor body executes -> can only intialize non-static members like this
Fixed::Fixed(): _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedPoint = source._fixedPoint;
}

Fixed& Fixed::operator=(const Fixed& source) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &source) //checks if the obj being assigned is the same as the source obj (ex. a = a;)
		return *this; // is so it returns without making changes
	else {
		this->_fixedPoint = source._fixedPoint;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}


void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPoint = raw;
}
