#include "Fixed.hpp"
#include <iostream>

int main( void ) {

	/* subject */
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;


	/* my test */
	Fixed c(10);
	Fixed d(20);
	Fixed e(30);
	Fixed f(40);
	Fixed g(50);

	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "g: " << g << std::endl;

	std::cout << "c + d: " << c + d << std::endl;
	std::cout << "c - d: " << c - d << std::endl;
	std::cout << "c * d: " << c * d << std::endl;
	std::cout << "c / d: " << c / d << std::endl;

	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;

	std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
	std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;

	std::cout << "f: " << f << std::endl;
	std::cout << "f++: " << f++ << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "++f: " << ++f << std::endl;
	std::cout << "f: " << f << std::endl;




	return 0;
}