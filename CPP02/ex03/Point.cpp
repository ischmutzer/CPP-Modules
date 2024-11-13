#include "Point.hpp"
#include <iostream>

Point::Point(): x(0), y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float xValue, const float yValue): x(xValue), y(yValue) {
	std::cout << "Parameterized constructor called" << std::endl;
}

Point::Point(const Point& source) {
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Point&	Point::operator=(const Point& source) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &source) {
		x.setRawBits(source.x.getRawBits());
		y.setRawBits(source.y.getRawBits());
	}
	return *this;
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}


