#include <iostream>
#include "iter.hpp"
#include "Colors.hpp"

void	printChar(const char& c) {
	std::cout << BLUE << c << RESET << std::endl;
}

void	printMultiplyByThree(int& num) {
	std::cout << BLUE << num * 3 << RESET << std::endl;
}

void	increment(int& num) {
	++num;
}

int main(void) {
	const char	chars[] = {'a', 'b', 'c', 'd', 'e', 'e'};
	int			integers[] = {1, 2, 3, 4, 5};

	std::cout << YELLOW << "\n-- Const iter --" << RESET << std::endl;
	iter(chars, 6, printChar);

	std::cout << YELLOW << "\n-- Non const iter --" << RESET << std::endl;
	iter(integers, 5, increment);
	iter(integers, 5, printMultiplyByThree);

	return (0);
}