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

		Fixed	getX() const;
		Fixed	getY() const;		

	private:
		const Fixed x;
		const Fixed	y;
};

#endif