/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:57:09 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/04 22:57:10 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include "../headers/Phonebook.hpp"
#include "../headers/Contact.hpp"

Phonebook::Phonebook(void) {
    this->filled = -1;
    std::cout << "Phonebook Builded!" << std::endl;
    return ;
}

Phonebook::~Phonebook() {
    std::cout << "Phonebook Destroyed" << std::endl;
    return ;
}

void Phonebook::menu(void) {
    char opt[8];

    do {
        memset(opt, 0, 8);
        this->printMenu();
        std::cin >> opt;
        if (std::cin.eof()) {
            return ;
        }
    }
    while (this->choice(opt));
    return ;
}

void Phonebook::add(void) {
    this->check();
    this->contactBuilder();
    return ;
}

void Phonebook::search(void) {
    int index = 0;

    if (this->filled >= 0) {
        std::cout << "\033[2J\033[1;1H";
        this->printTable();
        do { this->buildTable(index);
        } while (index++ < 8 && this->contacts[index].getStatus() == 1);
        this->request();
    } else { std::cout << "Phonebook is void.\nAdd a contact." << std::endl; }
    return ;
}

void Phonebook::exit(void) {
    std::cout << "Exit." << std::endl;
    return ;
}
