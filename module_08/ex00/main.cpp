#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void testVector(void) {
    std::vector<int>    vec;

    v.pushBack(5);
    v.pushBack(10);
    v.pushBack(15);
    v.pushBack(20);
    v.pushBack(25);
    
    for (int i = 5; i <= 30; i+=5) {
        try {
            std::vector<int>::iterator  i = easyfind(vec, 15);
            std::cout << "vector: " << BLUE << *i << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "vector: " << e.what() << RESET << std::endl;
        }
    }
}

static void testList(void) {
    std::list<int>  lst;

    lst.pushBack(5);
    lst.pushBack(10);
    lst.pushBack(15);
    lst.pushBack(20);

    for (int i = 5; i <= 25; i+=5) {
        try {
            std::vector<int>::iterator  i = easyfind(lst, 15);
            std::cout << "list: " << BLUE << *i << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "list: " << e.what() << RESET << std::endl;
        }
    }
}

static void testDeque(void) {
    std::deque<int> dq;

    dq.pushBack(5);
    dq.pushBack(10);
    dq.pushBack(15);
    dq.pushBack(20);

    for (int i = 5; i <= 25; i+=5) {
        try {
            std::vector<int>::iterator  i = easyfind(dq, 15);
            std::cout << "deque: " << BLUE << *i << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "deque: " << e.what() << RESET << std::endl;
        }
    }
}

static void testConstVector(void) {
    const std::vector<int>    vec(5, 10, 15, 20);
    
    for (int i = 5; i <= 30; i+=5) {
        try {
            std::vector<int>::const_iterator  i = easyfind(vec, 15);
            std::cout << "const vector: " << BLUE << *i << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "const vector: " << e.what() << RESET << std::endl;
        }
    }
}

int main(void) {
    std::cout << YELLOW << "-- Vector test --" << RESET << std::endl;
    testVector();
    std::cout << YELLOW << "-- List test --" << RESET << std::endl;
    testList();
    std::cout << YELLOW << "-- Deque test --" << RESET << std::endl;
    testDeque();
    std::cout << YELLOW << "-- Const Vector test --" << RESET << std::endl;
    testConstVector();
    
    return (0);
}