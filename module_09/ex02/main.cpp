#include "PmergeMe.hpp"
#include "Colors.hpp"

#include <iostream>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << RED << "Error: no args" << RESET << std::endl;
        std::cout << YELLOW << "Usage: ./PmergeMe <arg1> <arg2> ... <argn>" << RESET << std::endl;
        return (1);
    }
    try {
        PmergeMe merger = PmergeMe(argv);
        merger.process();
    }
    catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    return (0);
}