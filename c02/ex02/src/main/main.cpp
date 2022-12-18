
#include "Fixed.class.hpp"

int main()
{
	Fixed x(20);
	Fixed const y( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "first(x) = " << x << " and second(y) = " << y << std::endl;
	std::cout << "min = " << Fixed::min(x, y) << std::endl;
	std::cout << "x + y = " << x + y << std::endl;
	std::cout << "x - y = " << x - y << std::endl;
	std::cout << "x * y = " << x * y << std::endl;
	std::cout << "x / y = " << x / y << std::endl;
	if (x < y)
		std::cout << "x plus petit " << x << std::endl;
	else if (x <= y)
		std::cout << "x plus petit ou egal " << x << std::endl;
	else if (y < x)
		std::cout << "y plus petit " << y << std::endl;
	if (x > y)
		std::cout << "x plus grand " << x << std::endl;
	else if (x >= y)
		std::cout << "x plus grand ou egal " << std::endl;
	else if (y > x)
		std::cout << "y plus grand " << y << std::endl;
	if (x == y)
		std::cout << "x et y sont pareils " << std::endl;
	if (x != y)
		std::cout << "x et y ne sont pas pareils " << std::endl;

	std::cout << "x = " << x << std::endl;
	std::cout << "++x " << ++x << std::endl;
	std::cout << "x now = " << x << std::endl;
	std::cout << "x++ " << x++ << std::endl;
	std::cout << "x now = " << x << std::endl;
	std::cout << "--x " << --x << std::endl;
	std::cout << "x now = " << x << std::endl;
	std::cout << "x-- " << x-- << std::endl;
	std::cout << "x now = " << x << std::endl;


	std::cout << "y = " << y  << std::endl;
	std::cout << "max = " << Fixed::max( x, y ) << std::endl;
	return 0;
}