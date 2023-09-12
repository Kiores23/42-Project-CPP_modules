#include "Fixed.h"
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	// COMPARISON OPERATOR TEST
	if (!(Fixed(1) > Fixed(0)))
		std::cout << "Failure ";
	else if ((Fixed(1) < Fixed(0)))
		std::cout << "Failure ";
	else if (!(Fixed(1) == Fixed(1)))
		std::cout << "Failure ";
	else if (!(Fixed(1) >= Fixed(1)))
		std::cout << "Failure ";
	else if (!(Fixed(1.1f) > Fixed(1)))
		std::cout << "Failure ";
	else if ((Fixed(1.1f) == Fixed(1)))
		std::cout << "Failure ";
	else if ((Fixed(1.1f) == 1))
		std::cout << "Failure ";
	else if (!(Fixed(1) == 1))
		std::cout << "Failure ";
	else if ((Fixed(1) < 1))
		std::cout << "Failure ";
	else if (!(Fixed(1.5f) < 2.3f))
		std::cout << "Failure ";
	else
		std::cout << "Success ";
	std::cout << std::endl;
	return 0;
}