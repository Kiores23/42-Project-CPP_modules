#include "Point.h"
#include "Fixed.h"

Point::Point() : x(0), y(0) {}

Point::Point(const float cx, const float cy) : x(cx), y(cy) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point&	Point::operator=(const Point& other) {
	(void) other;
	return *this;
}

Fixed	Point::get_coordinates_x() const {
	return (x);
}

Fixed	Point::get_coordinates_y() const {
	return (y);
}