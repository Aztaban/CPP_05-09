#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void testVector(void) {
    std::vector<int>    vec;

    vec.push_back(10);
    vec.push_back(5);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(25);
    
    for (int i = 5; i <= 30; i+=5) {
        try {
            std::vector<int>::iterator  it = easyfind(vec, i);
            std::cout << "vector: " << BLUE << *it << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "vector: " << e.what() << RESET << std::endl;
        }
    }
}

static void testList(void) {
    std::list<int>  lst;

    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);

    for (int i = 5; i <= 25; i+=5) {
        try {
            std::vector<int>::iterator  it = easyfind(lst, i);
            std::cout << "list: " << BLUE << *it << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "list: " << e.what() << RESET << std::endl;
        }
    }
}

static void testDeque(void) {
    std::deque<int> dq;

    dq.push_back(5);
    dq.push_back(10);
    dq.push_back(15);
    dq.push_back(20);

    for (int i = 5; i <= 25; i+=5) {
        try {
            std::vector<int>::iterator  it = easyfind(dq, i);
            std::cout << "deque: " << BLUE << *it << RESET << std::endl;
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
            std::vector<int>::const_iterator  it = easyfind(vec, i);
            std::cout << "const vector: " << BLUE << *it << RESET << std::endl;
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