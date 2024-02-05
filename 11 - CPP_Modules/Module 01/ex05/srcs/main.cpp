/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:19:08 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 04:44:54 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Harl.hpp"

int main(void) {
    Harl        harl;
    std::string input;
    
    std::cout << "To close program type EXIT. Enjoy!" << std::endl;
    do {
        std::cout << "Insert Harl's complain: ";
        std::cin >> input;
        if (std::cin.eof()) {
            return (1);
        }
        harl.complain(input);
    } while (input.compare("EXIT"));
    return 0;
}