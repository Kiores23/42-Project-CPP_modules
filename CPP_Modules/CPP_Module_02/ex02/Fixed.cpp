#include "Fixed.h"
#include <iostream>
#include<cmath>

Fixed::Fixed()
{
	_number = 0;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::Fixed(const int n)
{
	_number = static_cast<int>(n * (1 << _byte)); 
}

Fixed::Fixed(const float n)
{
	_number = static_cast<int>(roundf(n * (1 << _byte)));
}

Fixed::~Fixed()
{
	;
}

int Fixed::getRawBits(void) const
{
	return (_number);
}

void Fixed::setRawBits(int const raw)
{
	_number = raw;
}

int	Fixed::toInt(void) const
{
	return (static_cast<int>(_number) / (1 << _byte));
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_number) / (1 << _byte));
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
    return _number < other._number;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _number <= other._number;
}

bool Fixed::operator>(const Fixed& other) const
{
    return _number > other._number;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _number >= other._number;
}

bool Fixed::operator<(const int& n) const
{
    return _number < static_cast<int>(n * (1 << _byte));
}

bool Fixed::operator<=(const int& n) const
{
    return _number <= static_cast<int>(n * (1 << _byte));
}

bool Fixed::operator>(const int& n) const
{
    return _number > static_cast<int>(n * (1 << _byte));
}

bool Fixed::operator>=(const int& n) const
{
    return _number >= static_cast<int>(n * (1 << _byte));
}

bool Fixed::operator<(const float& n) const
{
    return _number < static_cast<int>(n * (1 << _byte));
}

bool Fixed::operator<=(const float& n) const
{
    return _number <= static_cast<int>(n * (1 << _byte));
}

bool Fixed::operator>(const float& n) const
{
    return _number > static_cast<int>(n * (1 << _byte));
}

bool Fixed::operator>=(const float& n) const
{
    return _number >= static_cast<int>(roundf(n) * (1 << _byte));
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (*this != other)
		_number = other.getRawBits();
    return *this;
}

Fixed	Fixed::operator+(const Fixed& other)
{
	_number += other.getRawBits();
	return *this;
}

Fixed	Fixed::operator-(const Fixed& other)
{
	_number -= other.getRawBits();
	return *this;
}

Fixed	Fixed::operator*(const Fixed& other)
{
	_number *= other;
	return *this;
}

Fixed	Fixed::operator/(const Fixed& other)
{
	_number /= other;
	return *this;
}

Fixed	Fixed::operator=(int n)
{
    _number = static_cast<int>(n * (1 << _byte));
    return *this;
}

Fixed	Fixed::operator+(int n)
{
	_number += static_cast<int>(n * (1 << _byte));
	return *this;
}

Fixed	Fixed::operator-(int n)
{
	_number -= static_cast<int>(n * (1 << _byte));
	return *this;
}

Fixed	Fixed::operator*(int n)
{
	_number *= static_cast<int>(n * (1 << _byte));
	return *this;
}

Fixed	Fixed::operator/(int n)
{
	_number /= static_cast<int>(n * (1 << _byte));
	return *this;
}

Fixed	Fixed::operator=(float n)
{
    _number = static_cast<float>(n * (1 << _byte));
    return *this;
}

Fixed	Fixed::operator+(float n)
{
	_number += static_cast<float>(n * (1 << _byte));
	return *this;
}

Fixed	Fixed::operator-(float n)
{
	_number -= static_cast<float>(n * (1 << _byte));
	return *this;
}

Fixed	Fixed::operator*(float n)
{
	_number *= static_cast<float>(n * (1 << _byte));
	return *this;
}

Fixed	Fixed::operator/(float n)
{
	_number /= static_cast<float>(n * (1 << _byte));
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	_number++;
	return temp;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	_number--;
	return temp;
}

Fixed	Fixed::operator++()
{
	_number++;
	return *this;
}

Fixed	Fixed::operator--()
{
	_number--;
	return *this;
}

Fixed::operator float() const
{
	return (static_cast<float>(_number) / (1 << _byte));
}