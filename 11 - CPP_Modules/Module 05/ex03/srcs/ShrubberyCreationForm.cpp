/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:24:58 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/31 16:05:13 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecGrade()) {
        throw GradeTooLowException();
    }

    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    file << "     ccee88oo\n"
         << "  C8O8O8Q8PoOb o8oo\n"
         << " dOB69QO8PdUOpugoO9bD\n"
         << "CgggbU8OU qOp qOdoUOdcb\n"
         << "   6OuU  /p u gcoUodpP\n"
         << "      \\\\//  /douUP\n"
         << "        \\\\////\n"
         << "         |||/\\\n"
         << "         |||\\/\n"
         << "         |||||\n"
         << "   .....//||||\\....\n";
    file.close();
}


