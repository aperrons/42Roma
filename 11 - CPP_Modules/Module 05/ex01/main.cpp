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
#include "headers/Form.hpp"

int main(void) {

    Bureaucrat head = Bureaucrat("Head", 1);
    Bureaucrat mid = Bureaucrat("Mid", 70);
    Bureaucrat tail = Bureaucrat("Tail", 150);

    try {
        Form one = Form("Form one", 1, 1, false);
        std::cout << one << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form two = Form("Form two", 70, 70, false);
        std::cout << two << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try { 
        Form three = Form("Form three", 150, 150, false);
        std::cout << three << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    Form one = Form("Form one", 1, 1, false);
    std::cout << one << std::endl;
    Form two = Form("Form two", 70, 70, false);
    one = two;
    std::cout << one << std::endl;
    
    return 0;
}