#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_fixedPoint =  0;
}

Fixed::Fixed(const Fixed& source) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedPoint = source._fixedPoint;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& source) {
	if (this == &source) //checks if the obj being assigned is the same as the source obj (ex. a = a;)
		return *this; // is so it returns without making changes
	
}