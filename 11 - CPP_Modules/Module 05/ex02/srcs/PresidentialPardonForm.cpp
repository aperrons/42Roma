/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:16:40 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/31 17:46:34 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(const std::string& target)
        : AForm("PresidentialPardonForm", 25, 5, false, "target") {
        this->target_ = target;
    }

    PresidentialPardonForm(const PresidentialPardonForm& other)
        : AForm(other) {
        target_ = other.target_;
    }
/*
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other) {
        AForm::operator=(other);
        if (this != &other) {
            target_ = other.target_;
        }
        return *this;
    }*/

    virtual ~PresidentialPardonForm() {};

    virtual void action() const  {
        std::cout << "presidentiall" << std::endl;
    }

private:
    std::string target_;
};