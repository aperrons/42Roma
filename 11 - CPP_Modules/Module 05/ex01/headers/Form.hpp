/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:16:00 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/31 17:41:24 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "FormException.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

class Form {
    public:
        Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExecute, const bool isSigned);
        Form(const Form& form);
        Form& operator=(const Form& form);
        ~Form();

        const std::string&  getName() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        bool                getIsSigned() const;

        //void                beSigned(const Bureaucrat& bureaucrat);

    private: 
        const std::string   name_;
        const int           gradeToSign_;
        const int           gradeToExecute_;
        bool                isSigned_;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif