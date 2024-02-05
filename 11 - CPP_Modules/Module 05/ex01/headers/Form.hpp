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

#include <iostream>

class Form {
    public:
        Form();

        const std::string&  getName() const;
        const int           getGradeToSign() const;
        const int           getGradeToExecute() const;
        const bool          getIsSigned() const;

    private: 
        const std::string   name_;
        const int           gradeToSign_;
        const int           gradeToExecute_;
        bool                isSigned_;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif