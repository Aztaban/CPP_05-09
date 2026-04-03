#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "functions.hpp"
#include "Colors.hpp"

int main(void) {
	std::srand(std::time(0));
	Base*	pointer1 = generate();
	Base*	pointer2 = generate();
	Base*	pointer3 = generate();
	Base*	pointer4 = generate();

	std::cout << YELLOW << "\n-- Base 1 --" << RESET << std::endl;
	std::cout << std::left << std::setw(20) << "identify reference: ";
	identify(pointer1);
	std::cout << std::left << std::setw(20) << "identify pointer: ";
	identify(*pointer1);

	std::cout << YELLOW << "\n-- Base 2 --" << RESET << std::endl;
	std::cout << std::left << std::setw(20) << "identify reference: ";
	identify(pointer2);
	std::cout << std::left << std::setw(20) << "identify pointer: ";
	identify(*pointer2);

	std::cout << YELLOW << "\n-- Base 3 --" << RESET << std::endl;
	std::cout << std::left << std::setw(20) << "identify reference: ";
	identify(pointer3);
	std::cout << std::left << std::setw(20) << "identify pointer: ";
	identify(*pointer3);

	std::cout << YELLOW << "\n-- Base 4 --" << RESET << std::endl;
	std::cout << std::left << std::setw(20) << "identify reference: ";
	identify(pointer4);
	std::cout << std::left << std::setw(20) << "identify pointer: ";
	identify(*pointer4);
	std::cout << std::endl;

	delete pointer1;
	delete pointer2;
	delete pointer3;
	delete pointer4;

	return (0);
}