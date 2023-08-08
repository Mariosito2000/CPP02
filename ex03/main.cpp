#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {

	Point a(-3.71f, 8.65f);
	Point b(-1.45f, 1.17f);
	Point c(5.29f, 6.05f);
	Point punto(-2.45f, 2.17f);

	if (bsp(a, b, c, punto))
		std::cout << "TRUERS\n";
	else
		std::cout << "NOPPERS\n";
	return 0;
}