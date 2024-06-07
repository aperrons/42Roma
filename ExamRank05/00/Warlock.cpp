#include "Warlock.hpp"

// Constructor
Warlock::Warlock(const std::string& name, const std::string& title)
    : name(name), title(title) {
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

// Destructor
Warlock::~Warlock() {
    std::cout << this->name << ": My job here is done!" << std::endl;
}

// Getters
const std::string& Warlock::getName() const {
    return this->name;
}

const std::string& Warlock::getTitle() const {
    return this->title;
}

// Setter
void Warlock::setTitle(const std::string& title) {
    this->title = title;
}

// Introduce method
void Warlock::introduce() const {
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}
