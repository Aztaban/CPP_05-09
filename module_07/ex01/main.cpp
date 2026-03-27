#include <iostream>
#include "iter.hpp"
#include "Colors.hpp"

void    printChar(const char c) {
    std::cout << BLUE << c << RESET << std::endl;
}

void    multiplyByTwoAndPrint(int num) {
    std::cout << BLUE << num * 2 << RESET << std::endl;
}

void    increment(int& num) {
    ++num;
}

int main(void) {
    const char  chars[] = {'a', 'b', 'c', 'd', 'e', 'e'};
    int         integers[] = {1, 2, 3, 4, 5};

    std::cout << YELLOW << "\n-- Const iter --" << RESET << std::endl;
    iter(chars, (size_t)6, printChar);

    std::cout << YELLOW << "\n-- Non const iter --" << RESET << std::endl;
    iter(integers, (size_t)5, increment);
    iter(integers, (size_t)5, multiplyByTwoAndPrint);

    return (0);
}