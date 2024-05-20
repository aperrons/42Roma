/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:24:58 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/31 16:05:13 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/RobotomyRequestForm.hpp"
#include "headers/PresidentialPardonForm.hpp"
#include "headers/Intern.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Intern someRandomIntern;

        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Eve");
        AForm* unknown = someRandomIntern.makeForm("unknown form", "Unknown");

        if (shrubbery) {
            bob.signForm(*shrubbery);
            bob.executeForm(*shrubbery);
            delete shrubbery;
        }
        if (robotomy) {
            bob.signForm(*robotomy);
            bob.executeForm(*robotomy);
            delete robotomy;
        }
        if (pardon) {
            bob.signForm(*pardon);
            bob.executeForm(*pardon);
            delete pardon;
        }
        delete unknown; // should be NULL
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}