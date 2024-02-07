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

#include "../headers/Form.hpp"

Form::Form() : name_("Default"), gradeToSign_(150), gradeToExecute_(150), isSigned_(false)  {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute, const bool isSigned) : name_(name), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute), isSigned_(isSigned) {
    if (gradeToSign < 1 || gradeToExecute < 1) throw FormGradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw FormGradeTooLowException();
}

Form::Form(const Form& form) : name_(form.getName()), gradeToSign_(form.getGradeToSign()), gradeToExecute_(form.getGradeToExecute()), isSigned_(form.getIsSigned()) {}; 

Form &Form::operator=(const Form& form) {
    this->~Form();
    ::new(this) Form(form.getName(), form.getGradeToSign(), form.getGradeToExecute(), form.getIsSigned());
    return *this;
}

Form::~Form() {
    return ;
}

const std::string& Form::getName() const {
    return name_;
}

int Form::getGradeToSign() const {
    return gradeToSign_;
}

int Form::getGradeToExecute() const {
    return gradeToExecute_;
}

bool Form::getIsSigned() const {
    return isSigned_;
}
/*
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign_) { isSigned_ = true; } throw GradeTooLowException();
}*/

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << ":\n" << "- Grade to signature: " << form.getGradeToSign() << "\n" << "- Grade to execute: " << form.getGradeToExecute() << "\n" << "- Is signed: " << form.getIsSigned() << std::endl;
    return os;
}
/*
        std::cout << bureaucrat.getName() << " signed " << name_ << std::endl;
    } else {
        std::cout << bureaucrat.getName() << " could't sign " << name_ <<  std::endl;
    }
    */