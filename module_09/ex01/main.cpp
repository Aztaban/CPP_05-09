#include "RPN.hpp"

#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << RED << "Error" << RESET << std::endl;
        std::cerr << YELLOW << "Usage: ./RPN \"<expression>\"" << RESET << std::endl;
        return (1)
    }
    const rpn = RPN();
    try {
        rpn.calculate(argv[1]);
    }
    catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
	    return (1);
	}  
}