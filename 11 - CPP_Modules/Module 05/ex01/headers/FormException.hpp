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

#ifndef FORMEXCEPTION_HPP
#define FORMEXCEPTION_HPP

#include <exception>

class FormGradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Form grade too high";
        }
};

class FormGradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Form grade too low";
        }
};

#endif