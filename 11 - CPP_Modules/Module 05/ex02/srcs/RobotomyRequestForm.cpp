/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:24:58 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/31 16:05:13 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string& target)
        : AForm("RobotomyRequestForm", 72, 45, false, "target") {
        this->target_ = target;
    }

    RobotomyRequestForm(const RobotomyRequestForm& other)
        : AForm(other) {
        target_ = other.target_;
    }
/*
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other) {
        AForm::operator=(other);
        if (this != &other) {
            target_ = other.target_;
        }
        return *this;
    }*/

    virtual ~RobotomyRequestForm() {};

    virtual void action() const { 
       std::cout << "robotomy" << std::endl;
    }

private:
    std::string target_;
};