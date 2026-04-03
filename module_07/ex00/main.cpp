#include "whatever.hpp"
#include <iostream>
#include "Colors.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << BLUE << a << RESET << ", b = " << BLUE << b << RESET<< std::endl;
	std::cout << "min( a, b ) = " << BLUE << ::min( a, b ) << RESET << std::endl;
	std::cout << "max( a, b ) = " << BLUE << ::max( a, b ) << RESET << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = "<< BLUE << c << RESET << ", d = " << BLUE << d << RESET << std::endl;
	std::cout << "min( c, d ) = " << BLUE << ::min( c, d ) << RESET << std::endl;
	std::cout << "max( c, d ) = " << BLUE << ::max( c, d ) << RESET << std::endl;

	return 0;
}
