#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const float xValue, const float yValue);
		Point(const Point& source);
		Point&	operator=(const Point& source);
		~Point();

	private:
		const Fixed x;
		const Fixed	y;
};

#endif