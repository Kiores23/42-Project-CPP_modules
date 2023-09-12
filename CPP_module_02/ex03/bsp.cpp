#include "Point.h"
#include "Fixed.h"
#include <iostream>

float	E(Point	const a, Point const b, Point const point)
{
	float	n = (a.get_coordinates_x() - point.get_coordinates_x()) * (b.get_coordinates_y() - point.get_coordinates_y())
				- (a.get_coordinates_y() - point.get_coordinates_y()) * (b.get_coordinates_x() - point.get_coordinates_x());
	return (n);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (E(c, a, point) < 0 && E(a, b, point) < 0 && E(b, c, point) < 0)
		return (1);
	return (0);
}