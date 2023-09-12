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
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed&	operator=(const Fixed& other);
};

#endif