#ifndef POINT_H
# define POINT_H
# include "Fixed.h"

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(const float cx, const float cy);
	Point(const Point &other);
	~Point();
	Point&	operator=(const Point& other);
	Fixed	get_coordinates_x() const;
	Fixed	get_coordinates_y() const;
};

#endif