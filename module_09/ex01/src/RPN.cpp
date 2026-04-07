#include "RPN.hpp"

#include <stdexcept>
#include <sstream>
#include <cctype>

// CONSTRUCTORS AND DESTRUCTOR
RPN::RPN(void) {}

RPN::RPN(const RPN& copy) : _stack(copy._stack) {}

RPN::~RPN(void) {}

// OPERATOR OVERLOADS
RPN&    RPN::operator=(const RPN& copy) {
    if (this != &copy)
        _stack = copy._stack;
    return (*this);
}

// MEMBER FUNCTIONS
Operator    RPN::getOperator(const std::string& token) const {
    if (token == "+")
        return (ADD);
    if (token == "-")
        return (SUBSTRACT);
    if (token == "*")
        return (MUTLIPLY);
    if (token == "/")
        return (DIVIDE);
    return (INVALID)
}

void    RPN::useOperator(Operator op) {
    int left;
    int right;
    int result;
    
    if (_stack.size() < 2)
        throw std::runtime_error("Error: Invalid expression");
    left = _stack.top();
    _stack.pop();
    right = _stack.top();
    _stack.pop();
    switch (op) {
        case ADD:
            result = left + right;
            break;
        case SUBSTRACT:
            result = left - right;
            break;
        case MUTLIPLY:
            result = left * right;
            break;
        case DIVIDE
            if (right == 0)
                throw std::runtime_error("Error: Cannot divide by zero.")
            result = left / right;
            break;
        default:
            throw std::runtime_error("Error: invalid operator");
        _stack.push(result);
    }
}

int RPN::calculate(const std::string& expression) {
    std::stringstream   sstream(expression);
    std::string         token;

    while (ss >> token)
    {
        if (token.length() == 1 && std::isdigit(token[0]))
            _stack.push(token[0] - '0');
        else 
            useOperator(getOperator(token));
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: Not enough operators.");
    return (_stack.top());
}