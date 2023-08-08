#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called\n";
	this->value = a.getRawBits();
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits function called\n";
	return (this->value);
}

void	Fixed::setRawBits(int const Raw)
{
	std::cout << "setRawBits function called\n";
	this->value = Raw;
}

Fixed &	Fixed::operator = (const Fixed &a)
{
	std::cout << "Asignation operator called\n";
	this->value = a.getRawBits();
	return (*this);
}