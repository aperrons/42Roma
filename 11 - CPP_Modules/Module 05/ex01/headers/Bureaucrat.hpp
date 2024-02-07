/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:24:55 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/31 15:56:36 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "BureaucratException.hpp"
#include "Form.hpp"

#include <iostream>
#include <string>
 
class Bureaucrat {

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& bureaucrat);
        Bureaucrat& operator=(const Bureaucrat& bureaucrat);
        ~Bureaucrat();

        const std::string&  getName() const;
        int                 getGrade() const;
        void                incrementGrade();
        void                decrementGrade();

        //void                signForm(const Form& form);

    private:
        std::string name_;
        int         grade_; 
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif