
#include "Fixed.class.hpp"

int main()
{
	Fixed x( 69 );
	Fixed const y( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << Fixed::min(x, y) << std::endl;
	std::cout << x + y << std::endl;
	std::cout << x - y << std::endl;
	std::cout << x * y << std::endl;
	std::cout << x / y << std::endl;
	if (x < y)
		std::cout << "x " << x << std::endl;
	else
		std::cout << "y " << y << std::endl;
	if (x > y)
		std::cout << "x " << x << std::endl;
	else
		std::cout << "y " << y << std::endl;


	std::cout << x << std::endl;
	std::cout << ++x << std::endl;
	std::cout << x << std::endl;
	std::cout << x++ << std::endl;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << Fixed::max( x, y ) << std::endl;
	return 0;
}