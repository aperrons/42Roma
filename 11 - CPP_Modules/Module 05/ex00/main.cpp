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

int main(void) {

    try {
        Bureaucrat head = Bureaucrat("Head", 1);
        std::cout << head << std::endl;
        head.decrementGrade();
        std::cout << head << std::endl;
        head.incrementGrade();
        std::cout << head << std::endl;
        head.incrementGrade();
        std::cout << head << std::endl;
        head.incrementGrade();
        std::cout << head << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat tooHigh = Bureaucrat("TooHigh", 0);
        std::cout << tooHigh << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat tooLow = Bureaucrat("TooLow", 151);
        std::cout << tooLow << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    
    return 0;
}