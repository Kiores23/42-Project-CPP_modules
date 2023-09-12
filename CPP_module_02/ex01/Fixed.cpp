#include "Fixed.h"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	number = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	number = static_cast<int>(n * (1 << byte)); 
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	number = static_cast<int>(roundf(n * (1 << byte)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (number);
}

void Fixed::setRawBits(int const raw)
{
	number = raw;
}

int	Fixed::toInt( void ) const
{
	return (static_cast<int>(number) / (1 << byte));
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(number) / (1 << byte));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        number = other.getRawBits();
    }
    return *this;
}

Fixed::operator float() const
{
	return (static_cast<float>(number) / (1 << byte));
}