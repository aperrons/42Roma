/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:25:05 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/31 15:59:06 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade() {
    checkGrade(_grade + 1);
    _grade++;
}

void Bureaucrat::signForm(AForm& form) const {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Bureaucrat::checkGrade(int grade) {
    if (grade < maxGrade) {
        throw GradeTooHighException();
    } else if (grade > minGrade) {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
