/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:16:00 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/31 17:41:24 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm() = 0;

    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

    void checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
