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

#ifndef AFORM_HPP
#define AFORM_HPP

#include "FormException.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute, const bool isSigned, const std::string target);
        AForm(const AForm& form);
        //AForm& operator=(const AForm& form);
        virtual ~AForm();

        const std::string&  getName() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        bool                getIsSigned() const;

        void                setIsSigned(const bool value);
        void                beSigned(const Bureaucrat& bureaucrat) const;

        virtual void execute(Bureaucrat const & executor) const {
           /* if (!isSigned_) {
                throw std::runtime_error("Form is not signed.");
            }
            if (executor.getGrade() > gradeToExecute_) {
                throw std::runtime_error("Bureaucrat's grade too low to execute this form.");
            }*/
            action(executor);
        }

        virtual void action(Bureaucrat const& bureaucrat) const = 0;


    private: 
        const std::string   name_;
        const int           gradeToSign_;
        const int           gradeToExecute_;
        bool                isSigned_;
        const std::string   target_;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif