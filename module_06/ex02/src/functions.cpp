#include <stdlib.h>
#include <ctime>
#include <iostream>
#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Colors.hpp"

Base*	generate(void) {
	int n = std::rand() % 3;

	if (n == 0)
		return (new A);
	else if (n == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base* pointer) {
	if (dynamic_cast<A*>(pointer))
		std::cout << BLUE << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(pointer))
		std::cout << BLUE << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(pointer))
		std::cout << BLUE << "C" << RESET << std::endl;
}

void	identify(Base& pointer) {
	try {
		(void)dynamic_cast<A&>(pointer);
		std::cout << BLUE << "A" << RESET << std::endl;
	} 
	catch (std::exception& e) {}

	try {
		(void)dynamic_cast<B&>(pointer);
		std::cout << BLUE << "B" << RESET << std::endl;
	}
	catch (std::exception& e) {}

	try {
		(void)dynamic_cast<C&>(pointer);
		std::cout << BLUE << "C" << RESET << std::endl;
	}
	catch (std::exception& e) {}
}