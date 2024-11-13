#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPoint(0) {
	std::cout << "Deafult constructor called" << std::endl;
}

Fixed::Fixed(const int intVar) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = intVar << _fractionalBits;
}

Fixed::Fixed(const float floatVar) {
	std::cout << "Float constructor called" << std::endl;
    _fixedPoint = roundf(floatVar * (1 << _fractionalBits));
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
	
	if (this != &source)
		this->_fixedPoint = source.getRawBits();
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
    return static_cast<float>(_fixedPoint) / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return _fixedPoint >> _fractionalBits;
}

std::ostream&	operator<<(std::ostream& outStream, const Fixed& fixedPointValue) {
	outStream << fixedPointValue.toFloat();
	return outStream;
}

//greater than
bool	Fixed::operator>(const Fixed& source) const {
	if (this->_fixedPoint > source._fixedPoint) {
		return true;
	}
	return false;
}

//less than
bool	Fixed::operator<(const Fixed& source) const {
	if (this->_fixedPoint < source._fixedPoint)
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed& source) const {
	if (this->_fixedPoint >= source._fixedPoint)
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed& source) const {
	if (this->_fixedPoint <= source._fixedPoint)
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed& source) const {
	if (this->_fixedPoint == source._fixedPoint)
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed& source) const {
	if (this->_fixedPoint != source._fixedPoint)
		return true;
	return false;
}

Fixed	Fixed::operator+(const Fixed& source) {
	Fixed	sum;

	sum._fixedPoint = this->_fixedPoint + source._fixedPoint;
	return sum;
}

Fixed	Fixed::operator-(const Fixed& source) {
	Fixed	diff;

	diff._fixedPoint = this->_fixedPoint - source._fixedPoint;
	return diff;
}

Fixed	Fixed::operator*(const Fixed& source) {
	Fixed	res;

	res._fixedPoint = (this->_fixedPoint * source._fixedPoint) >>_fractionalBits;
	return res;
}

Fixed	Fixed::operator/(const Fixed& source) {
	Fixed	div;

	div._fixedPoint = ((this->_fixedPoint << _fractionalBits) / source._fixedPoint);
	return div;
}

//++x
Fixed&	Fixed::operator++() {
	++_fixedPoint;
	return *this;
}

//x++
Fixed	Fixed::operator++(int) {
	Fixed	temp = *this;
	++_fixedPoint;
	return temp;
}

Fixed&	Fixed::operator--() {
	--_fixedPoint;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	temp = *this;
	--_fixedPoint;
	return temp;
}

Fixed&	Fixed::min(Fixed& num1, Fixed& num2) {
	if (num1._fixedPoint < num2._fixedPoint)
		return	num1;
	return num2;
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2) {
	if (num1._fixedPoint < num2._fixedPoint)
		return	num1;
	return	num2;
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2) {
	if (num1._fixedPoint > num2._fixedPoint)
		return num1;
	return num2;
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2) {
	if (num1._fixedPoint > num2._fixedPoint)
		return	num1;
	return num2;
}

