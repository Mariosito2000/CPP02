#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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

/*---MEMBER FUNCTIONS---*/

	int		getRawBits() const;
	void	setRawBits(int const raw);

/*---OPERATORS---*/

	Fixed &	operator = (const Fixed &);

};

#endif