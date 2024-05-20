/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:16:40 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/31 17:46:34 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    checkGrade(signGrade);
    checkGrade(execGrade);
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

void AForm::checkGrade(int grade) {
    if (grade < Bureaucrat::maxGrade) {
        throw GradeTooHighException();
    } else if (grade > Bureaucrat::minGrade) {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() << ", sign grade " << form.getSignGrade() << ", exec grade " << form.getExecGrade();
    os << (form.isSigned() ? " [Signed]" : " [Not Signed]");
    return os;
}
