/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:57:17 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/04 23:05:36 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "../headers/Phonebook.hpp"
#include "../headers/Contact.hpp"

void Phonebook::check(void) {
    if (this->filled == 7) {
        this->filled = 0;
    } else {
        this->filled++;
    }
    return ;
}

void Phonebook::printTable(void) {
    std::cout.width(10);
    std::cout << "iD" << "|";
    std::cout.width(10);
    std::cout << "FirstName" << "|";
    std::cout.width(10);
    std::cout << "LastName" << "|";
    std::cout.width(10);
    std::cout << "NickName" << "|" << std::endl;
}

void Phonebook::buildTable(int index) {
    std::cout.width(10);
    std::cout << index << "|";
    std::cout.width(10);
    std::cout << truncate(this->contacts[index].getFirstName(), 9) << "|";
    std::cout.width(10);
    std::cout << truncate(this->contacts[index].getLastName(), 9) << "|";
    std::cout.width(10);
    std::cout << truncate(this->contacts[index].getNickName(), 9) << "|" << std::endl;
}

void Phonebook::printMenu(void) {
    std::cout << "\t\t\t---|      Phonebook     |---\n" << std::endl; 
    std::cout << "\t\t\t---|ADD                 |---\n" << std::endl;
    std::cout << "\t\t\t---|SEARCH              |---\n" << std::endl;
    std::cout << "\t\t\t---|EXIT                |---\n" << std::endl;
}

int Phonebook::choice(const char *opt) {
    if (!strcmp(opt, "ADD")) {
        this->add();
        return (1);
    }
    else if (!strcmp(opt, "SEARCH")) {
       this->search();
        return (1);
    }
    else if (!strcmp(opt, "EXIT")) {
        this->exit();
        return (0);
    }
    else { std::cout << "-_-\n" << std::endl;
        return (1);
    }
    return(0);
}

void Phonebook::contactBuilder(void) {
    this->contacts[this->filled].setFirstName();
    this->contacts[this->filled].setLastName();
    this->contacts[this->filled].setNickName();
    if (this->contacts[this->filled].setPhoneNumber()) {
    } else {
        this->filled--; 
        return ;}
    this->contacts[this->filled].setDarkestSecret();
    this->contacts[this->filled].setStatus();
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Contact Builded!" << std::endl;
    return ;
}

std::string Phonebook::truncate(std::string string, int width) {
    if (strlen(string.c_str()) > 10) {
        return (string.substr(0, width) + ".");
    }
    return (string);
}

void Phonebook::request(void) {
    char    input[500];
    int     i = 0;
    int     request;

    memset(input, 0, 3);
    std::cout << "\nInsert iD for contact information: ";
    do { std::cin.getline(input, 500);
    } while (strlen(input) == 0);
    while (input[i]) {
        if (isdigit(input[i])) {
            i++;
        } else {
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Insert right request." << std::endl;
            return ;
        }
    }
    request = std::atoi(input);
    if (request < 0 || request > 7) {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Insert right request." << std::endl;
    } else {
        std::cout << std::endl;
        this->printTable();
        this->buildTable(request);
        this->printUser(request);
    }
    return ;
}

void Phonebook::printUser(int index) {
    if (this->contacts[index].getStatus() == 1) {
        std::cout << "iD: " << index << std::endl;
        std::cout << "FirstName: " << this->contacts[index].getFirstName() << std::endl;
        std::cout << "LastName: " << this->contacts[index].getLastName() << std::endl;
        std::cout << "NickName: " << this->contacts[index].getNickName() << std::endl;
        std::cout << "PhoneNUmber: " << this->contacts[index].getPhoneNumber() << std::endl;
        std::cout << "DarkestSecret: " << this->contacts[index].getDarkestSecret() << std::endl;
        do { std::cout << '\n' << "Press Enter to continue...";
        } while (std::cin.get() != '\n');
        std::cout << "\033[2J\033[1;1H";
    } else {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Contact not found." << std::endl;
    }
    return ;
}
