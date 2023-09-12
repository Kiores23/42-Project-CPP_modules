#ifndef FIXED_H
# define FIXED_H

class Fixed
{
private:
	int					number;
	static const int	byte = 8;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();
	// FUNCTION
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	int				toInt( void ) const;
	float 			toFloat( void ) const;
	static float	min( float &n1, float &n2);
	static float	min( const float &n1, const float &n2);
	static float	max( float &n1, float &n2);
	static float	max( const float &n1, const float &n2);
	// OPERATOR 1
	bool	operator<(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator>(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<(const int &n) const;
	bool	operator<=(const int &n) const;
	bool	operator>(const int &n) const;
	bool	operator>=(const int &n) const;
	bool	operator<(const float &n) const;
	bool	operator<=(const float &n) const;
	bool	operator>(const float &n) const;
	bool	operator>=(const float &n) const;
	// OPERATOR 2
	Fixed&	operator=(const Fixed& other);
	Fixed	operator+(const Fixed& other);
	Fixed	operator-(const Fixed& other);
	Fixed	operator*(const Fixed& other);
	Fixed	operator/(const Fixed& other);
	Fixed	operator=(int n);
	Fixed	operator+(int n);
	Fixed	operator-(int n);
	Fixed	operator*(int n);
	Fixed	operator/(int n);
	Fixed	operator=(float n);
	Fixed	operator+(float n);
	Fixed	operator-(float n);
	Fixed	operator*(float n);
	Fixed	operator/(float n);
	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed	operator++();
	Fixed	operator--();
	operator float() const;
};

#endif