#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN {

private:
    enum Operator {
        ADD,
        SUBSTRACT,
        MULTIPLY,
        DIVIDE,
        INVALID
    }

    std::stack<int> _stack;
    Operator    getOperator(const std::string& token) const;
    void        useOperator(Operator op);

public:
    RPN(void);
    RPN(const RPN& copy);
    RPN&    operator=(const RPN& copy);
    ~RPN(void);

    int calculate(const std::string& expression);
};

#endif