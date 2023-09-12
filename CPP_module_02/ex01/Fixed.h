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
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt( void ) const;
	float 	toFloat( void ) const;
	Fixed&	operator=(const Fixed& other);
	operator float() const;
};

#endif