#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:

	int					value;
	const int static	fractionalBits = 8;

public:

/*---CONST/DEST---*/

	Fixed();
	~Fixed();

	Fixed(const Fixed &);
	Fixed(const int);
	Fixed(const float);

/*---MEMBER FUNCTIONS---*/

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;

/*---OPERATORS---*/

	Fixed &	operator = (const Fixed &);

};

std::ostream& operator<<(std::ostream& os, const Fixed &);

#endif