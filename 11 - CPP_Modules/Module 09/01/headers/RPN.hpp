#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN {
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int evaluate(const std::string& expression);

private:
    std::stack<int> stack;

    bool isOperator(char c) const;
    int performOperation(char op, int a, int b) const;
};

#endif