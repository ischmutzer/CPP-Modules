#include "Fixed.hpp"

Fixed::Fixed() {
	_fixedPoint =  0;
}

Fixed::Fixed(const Fixed& source) {
	_fixedPoint = source._fixedPoint;
}

Fixed::~Fixed() {}