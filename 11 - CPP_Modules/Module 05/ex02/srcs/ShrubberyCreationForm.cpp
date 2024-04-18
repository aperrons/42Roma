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

#include "../headers/AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(const std::string& target)
        : AForm("ShrubberyCreationForm", 145, 137, false, target) {}

    virtual void action(Bureaucrat const & executor) const {
        if (executor.signForm(*this)) {
            std::cout << "       ###\n      #o###\n    #####o###\n   #o#\\#|#/###\n    ###\\|/#o#\n     # }|{  #\n       }|{" << std::endl;
        }       
    }
};
