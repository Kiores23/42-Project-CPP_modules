#include "Fixed.h"
#include "Point.h"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
	Point	a(-1, -1);
	Point	b(-1, 1);
	Point	c(1, 0);
	Point	point1(0, 0);
	Point	point2(-1, 10);
	Point	point3(0.3f, 0.3f);

	if (!bsp(a, b, c, point1))
		std::cout << "Failure 1";
	else if (bsp(a, b, c, a))
		std::cout << "Failure 2";
	else if (bsp(a, b, c, b))
		std::cout << "Failure 3";
	else if (bsp(a, b, c, c))
		std::cout << "Failure 4";
	else if (bsp(a, b, c, point2))
		std::cout << "Failure 5";
	else if (!bsp(a, b, c, point3))
		std::cout << "Failure 6";	
	else
		std::cout << "Success ";
	std::cout << std::endl;
	return 0;
}