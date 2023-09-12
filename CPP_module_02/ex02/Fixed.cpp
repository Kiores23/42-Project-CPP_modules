#include "Fixed.h"
#include <iostream>
#include<cmath>

Fixed::Fixed()
{
	number = 0;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::Fixed(const int n)
{
	number = static_cast<int>(n * (1 << byte)); 
}

Fixed::Fixed(const float n)
{
	number = static_cast<int>(roundf(n * (1 << byte)));
}

Fixed::~Fixed()
{
	;
}

int Fixed::getRawBits(void) const
{
	return (number);
}

void Fixed::setRawBits(int const raw)
{
	number = raw;
}

int	Fixed::toInt(void) const
{
	return (static_cast<int>(number) / (1 << byte));
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(number) / (1 << byte));
}

float	Fixed::min( float &n1, float &n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

float	Fixed::min( const float &n1, const float &n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

float	Fixed::max( float &n1, float &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

float	Fixed::max( const float &n1, const float &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

bool Fixed::operator<(const Fixed& other) const
{
    return number < other.number;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return number <= other.number;
}

bool Fixed::operator>(const Fixed& other) const
{
    return number > other.number;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return number >= other.number;
}

bool Fixed::operator<(const int& n) const
{
    return number < static_cast<int>(n * (1 << byte));
}

bool Fixed::operator<=(const int& n) const
{
    return number <= static_cast<int>(n * (1 << byte));
}

bool Fixed::operator>(const int& n) const
{
    return number > static_cast<int>(n * (1 << byte));
}

bool Fixed::operator>=(const int& n) const
{
    return number >= static_cast<int>(n * (1 << byte));
}

bool Fixed::operator<(const float& n) const
{
    return number < static_cast<int>(n * (1 << byte));
}

bool Fixed::operator<=(const float& n) const
{
    return number <= static_cast<int>(n * (1 << byte));
}

bool Fixed::operator>(const float& n) const
{
    return number > static_cast<int>(n * (1 << byte));
}

bool Fixed::operator>=(const float& n) const
{
    return number >= static_cast<int>(roundf(n) * (1 << byte));
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (*this != other)
		number = other.getRawBits();
    return *this;
}

Fixed	Fixed::operator+(const Fixed& other)
{
	number += other.getRawBits();
	return *this;
}

Fixed	Fixed::operator-(const Fixed& other)
{
	number -= other.getRawBits();
	return *this;
}

Fixed	Fixed::operator*(const Fixed& other)
{
	number *= other;
	return *this;
}

Fixed	Fixed::operator/(const Fixed& other)
{
	number /= other;
	return *this;
}

Fixed	Fixed::operator=(int n)
{
    number = static_cast<int>(n * (1 << byte));
    return *this;
}

Fixed	Fixed::operator+(int n)
{
	number += static_cast<int>(n * (1 << byte));
	return *this;
}

Fixed	Fixed::operator-(int n)
{
	number -= static_cast<int>(n * (1 << byte));
	return *this;
}

Fixed	Fixed::operator*(int n)
{
	number *= static_cast<int>(n * (1 << byte));
	return *this;
}

Fixed	Fixed::operator/(int n)
{
	number /= static_cast<int>(n * (1 << byte));
	return *this;
}

Fixed	Fixed::operator=(float n)
{
    number = static_cast<float>(n * (1 << byte));
    return *this;
}

Fixed	Fixed::operator+(float n)
{
	number += static_cast<float>(n * (1 << byte));
	return *this;
}

Fixed	Fixed::operator-(float n)
{
	number -= static_cast<float>(n * (1 << byte));
	return *this;
}

Fixed	Fixed::operator*(float n)
{
	number *= static_cast<float>(n * (1 << byte));
	return *this;
}

Fixed	Fixed::operator/(float n)
{
	number /= static_cast<float>(n * (1 << byte));
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	number++;
	return temp;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	number--;
	return temp;
}

Fixed	Fixed::operator++()
{
	number++;
	return *this;
}

Fixed	Fixed::operator--()
{
	number--;
	return *this;
}

Fixed::operator float() const
{
	return (static_cast<float>(number) / (1 << byte));
}