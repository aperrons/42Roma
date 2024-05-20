#include "headers/Functions.hpp"

int main() {
    Base* base = generate();

    std::cout << "Identify by pointer: ";
    identify(base);

    std::cout << "Identify by reference: ";
    identify(*base);

    delete base;
    return 0;
}