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
#include "headers/AForm.hpp"
#include "srcs/PresidentialPardonForm.cpp"
#include "srcs/RobotomyRequestForm.cpp"
#include "srcs/ShrubberyCreationForm.cpp"


int main(void) {

    Bureaucrat head = Bureaucrat("Head", 2);
    Bureaucrat mid = Bureaucrat("Mid", 70);
    Bureaucrat tail = Bureaucrat("Tail", 150);

    try {
        ShrubberyCreationForm one = ShrubberyCreationForm("home");
        one.execute(tail);
       
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
/*
    try {
        RobotomyRequestForm two = RobotomyRequestForm();
        //std::cout << two.execute(mid) << std::endl;
        two.execute(mid);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try { 
        ShrubberyCreationForm three = ShrubberyCreationForm();
        //std::cout << three.execute(tail) << std::endl;
        three.execute(tail);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }*/

   // AForm one = AForm("Form one", 1, 1, false);
    //std::cout << one << std::endl;
  //  Form two = Form("Form two", 70, 70, false);
   // one = two;
    //std::cout << one << std::endl;
    
   // one.beSigned(head);
   //head.signForm(one);
    return 0;
}