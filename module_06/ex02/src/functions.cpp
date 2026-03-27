#include <cstdlib>
#include <ctime>
#include <iostream>
#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void) {
    int n = std::rand() % 3;

    if (n == 0)
        return (new A);
    else if (n == 1)
        return (new B);
    else
        return (new C)
}

void    identify(Base* pointer) {
    if (dynamic_cast<A*>(pointer))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(pointer))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(pointer))
        std::cout << "C" << std::endl;
}

void    identify(Base& pointer) {
    try {
        (void)dynamic_cast<A&>(pointer)
        std::cout << "A" << std::endl;
    } 
    catch (std::exception& e) {}

    try {
        (void)dynamic_cast<B&>(pointer)
        std::cout << "B" << std::endl;
    }
    catch (std::exception& e) {}

    try {
        (void)dynamic_cast<C&>(pointer)
        std::cout << "C" << std::endl;
    }
    catch (std::exception& e) {}
}