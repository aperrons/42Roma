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

AForm::AForm() : name_("Default"), gradeToSign_(150), gradeToExecute_(150), isSigned_(false), target_("null") {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute, const bool isSigned, const std::string target) : name_(name), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute), isSigned_(isSigned), target_(target) {
    if (gradeToSign < 1 || gradeToExecute < 1) throw FormGradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw FormGradeTooLowException();
}

AForm::AForm(const AForm& form) : name_(form.getName()), gradeToSign_(form.getGradeToSign()), gradeToExecute_(form.getGradeToExecute()), isSigned_(form.getIsSigned()) {}; 
/*
AForm &AForm::operator=(AForm form) {
        swap(*this, form);
        return *this;
}*/

AForm::~AForm() {
    return ;
}

const std::string& AForm::getName() const {
    return name_;
}

int AForm::getGradeToSign() const {
    return gradeToSign_;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute_;
}

bool AForm::getIsSigned() const {
    return isSigned_;
}

void AForm::setIsSigned(const bool value) {
    this->isSigned_ = value;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) const {
    if (bureaucrat.getGrade() <= gradeToSign_) { } else { throw GradeTooLowException(); }
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName() << ":\n" << "- Grade to signature: " << form.getGradeToSign() << "\n" << "- Grade to execute: " << form.getGradeToExecute() << "\n" << "- Is signed: " << form.getIsSigned() << std::endl;
    return os;
}
/*
        std::cout << bureaucrat.getName() << " signed " << name_ << std::endl;
    } else {
        std::cout << bureaucrat.getName() << " could't sign " << name_ <<  std::endl;
    }
    */