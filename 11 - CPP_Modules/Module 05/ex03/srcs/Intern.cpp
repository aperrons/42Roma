#include "../headers/Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
        // No data members to copy in this case
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*formCreators[])(const std::string&) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }

    std::cerr << "Error: Form name '" << formName << "' does not exist." << std::endl;
    return NULL;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}
