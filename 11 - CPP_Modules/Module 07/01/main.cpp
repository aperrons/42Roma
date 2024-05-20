#include "headers/Iter.hpp"
#include <iostream>

void increment(int& x) {
    x++;
}

void printInt(int& x) {
    std::cout << x << " ";
}

void printString(std::string& str) {
    std::cout << str << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    unsigned int intLength = 5;

    std::cout << "Original intArray: ";
    iter(intArray, intLength, printInt);
    std::cout << std::endl;

    iter(intArray, intLength, increment);

    std::cout << "Incremented intArray: ";
    iter(intArray, intLength, printInt);
    std::cout << std::endl;

    std::string stringArray[] = {"Hello", "World", "!"};
    unsigned int stringLength = 3;

    std::cout << "Original stringArray: ";
    iter(stringArray, stringLength, printString);
    std::cout << std::endl;

    return 0;
}
