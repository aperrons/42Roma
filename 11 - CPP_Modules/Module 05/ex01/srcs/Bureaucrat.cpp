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

Bureaucrat::Bureaucrat() : name_("Default"), grade_(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name_(bureaucrat.getName()), grade_(bureaucrat.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
    if (this != &bureaucrat) {
        name_ = bureaucrat.name_;
        grade_ = bureaucrat.grade_;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    return ;
}

const std::string& Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

void Bureaucrat::incrementGrade() {
    if (--(this->grade_) < 1) throw GradeTooHighException();
    std::cout << "Bureaucrat " << this->getName() << " rises in rank" << std::endl;
}

void Bureaucrat::decrementGrade() {
    if (++(this->grade_) > 150) throw GradeTooLowException();
    std::cout << "Bureaucrat " << this->getName() << " go down a grade" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat " << bureaucrat.getName() << " has grade " << bureaucrat.getGrade() << std::endl;
    return os;
}
