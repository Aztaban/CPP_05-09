#include <cstdlib>
#include <ctime>
#include <iostream>
#include "functions.hpp"
#include "Colors.hpp"

int main(void) {
	std::srand(std::time(0));
	Base*	pointer1 = generate();
	Base*	pointer2 = generate();
	Base*	pointer3 = generate();
	Base*	pointer4 = generate();

	std::cout << YELLOW << "\n-- Base 1 --" << std::endl;
	std::cout << BLUE << "identify reference: " << RESET;
	identify(pointer1);
	std::cout << BLUE << "identify pointer: " << RESET;
	identify(*pointer1);

	std::cout << YELLOW << "\n-- Base 2 --" << std::endl;
	std::cout << BLUE << "identify reference: " << RESET;
	identify(pointer2);
	std::cout << BLUE << "identify pointer: " << RESET;
	identify(*pointer2);

	std::cout << YELLOW << "\n-- Base 3 --" << std::endl;
	std::cout << BLUE << "identify reference: " << RESET;
	identify(pointer3);
	std::cout << BLUE << "identify pointer: " << RESET;
	identify(*pointer3);

	std::cout << YELLOW << "\n-- Base 4 --" << std::endl;
	std::cout << BLUE << "identify reference: " << RESET;
	identify(pointer4);
	std::cout << BLUE << "identify pointer: " << RESET;
	identify(*pointer4);

	delete pointer1;
	delete pointer2;
	delete pointer3;
	delete pointer4;

	return (0);
}