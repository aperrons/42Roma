#include "../headers/RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) : stack(other.stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        stack = other.stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            if (stack.size() < 2) {
                throw std::runtime_error("invalid expression");
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = performOperation(token[0], a, b);
            stack.push(result);
        } else {
            int num = std::atoi(token.c_str());
            if (num >= 0 && num < 10) {
                stack.push(num);
            } else {
                throw std::runtime_error("invalid number");
            }
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("invalid expression");
    }

    return stack.top();
}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(char op, int a, int b) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                throw std::runtime_error("division by zero");
            }
            return a / b;
        default: 
            throw std::runtime_error("unknown operator");
    }
}