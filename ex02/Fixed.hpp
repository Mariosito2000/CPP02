#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:

	int	value;
	const int static fractional_bits = 8;

public:

/*---CONST/DEST---*/

	Fixed();
	~Fixed();

	Fixed(const Fixed &);
	Fixed(const int);
	Fixed(const float);

/*---STATIC FUNCTIONS---*/

	static	Fixed & min(Fixed &, Fixed &);
	static const	Fixed & min(const Fixed &, const Fixed &);
	static	Fixed & max(Fixed &, Fixed &);
	static const	Fixed & max(const Fixed &, const Fixed &);

/*---MEMBER FUNCTIONS---*/

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;

/*---OPERATORS---*/

	Fixed &	operator = (const Fixed &);

	bool	operator > (const Fixed &) const;
	bool	operator < (const Fixed &) const;
	bool	operator >= (const Fixed &) const;
	bool	operator <= (const Fixed &) const;
	bool	operator == (const Fixed &) const;
	bool	operator != (const Fixed &) const;

	Fixed &	operator ++ ();
	Fixed	operator ++ (int);
	Fixed &	operator -- ();
	Fixed	operator -- (int);
};

Fixed	operator + (const Fixed &, const Fixed &);
Fixed	operator - (const Fixed &, const Fixed &);
Fixed	operator * (const Fixed &, const Fixed &);
Fixed	operator / (const Fixed &, const Fixed &);

std::ostream& operator<<(std::ostream& os, const Fixed &);

#endif