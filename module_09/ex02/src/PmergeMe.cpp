#include "PmergeMe.hpp"

#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <iostream>
#include <ctime>

// CONSTRUCTORS AND DESTRUCTOR
PmergMe::PmergMe(void) {}

PmergMe::PmergMe(char **argv) {
    parseInput(argv);
}

PmergMe::PmergMe(const PmergMe& copy) : _vector(copy._vector), _deque(copy._deque) {}

PmergMe::~PmergMe(void) {}

// OPERATORS OVERLOADS

PmergMe&    PmergMe::operator=(const PmergMe& copy) {
    if (this != &copy) {
        _vector = copy._vector;
        _deque = copy._deque;
    }
    return (*this);
}

// MEMBER FUNCTIONS
int    PmergMe::parsePositiveInteger(const std::string& token) const {
    std::stringstream   sstream(token);
    long    value;
    char    extra;

    if (!(ss >> value) || (ss >> extra))
        throw std::runtime_error("Error: invalid integer");
    if (value < 0 || value > INT_MAX)
        throw std::runtime_error("Error: invalid integer");
    return (static_cast<int>(value));
}

bool    PmergMe::isDuplicate(int value) const {
    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); it++) {
        if (*it == value)
            return (true);
    }
    return (false);
}

void    PmergMe::parseInput(char **argv) {
    int i = 1;
    int value;

    while (argv[i]) {
        value = parsePositiveInteger(argv[i])
        if (isDuplicate(value))
            throw std::runtime_error("Error: input contains duplicates");
        _vector.push_back(value);
        _deque.push_back(value);
        i++;
    }
    if (_vector.empty())
        throw std::runtime_error("Error: parsing failed")
}