/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:56:55 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/04 20:56:57 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdio>
#include "../headers/Contact.hpp"

Contact::Contact() {
    this->initFirstName("");
    this->initLastName("");
    this->initNickName("");
    this->initPhoneNumber("");
    this->initDarkestSecret("");
    return ;
}

Contact::~Contact(void) {
    return ;
}

void    Contact::initFirstName(std::string firstName) {
    this->_firstName = firstName;
    return ;
}

void    Contact::initLastName(std::string lastName) {
    this->_lastName = lastName;
    return ;
}

void    Contact::initNickName(std::string nickName) {
    this->_nickName = nickName;
    return ;
}

void    Contact::initPhoneNumber(std::string phoneNumber) {
    this->_phoneNumber = phoneNumber;
    return ;
}

void    Contact::initDarkestSecret(std::string darkestSecret) {
    this->_darkestSecret = darkestSecret;
    return ;
}

void    Contact::initStatus(void) {
    this->_status = 0;
    return ;
}

std::string Contact::getFirstName(void) const {
    return this->_firstName;
}

std::string Contact::getLastName(void) const {
    return this->_lastName;
}

std::string Contact::getNickName(void) const {
    return this->_nickName;
}

std::string Contact::getPhoneNumber(void) const {
    return this->_phoneNumber;
}

std::string Contact::getDarkestSecret(void) const {
    return this->_darkestSecret;
}

int Contact::getStatus(void) const {
    return this->_status;
}

void    Contact::setFirstName(void) {
    char    input[100];
    
    memset(input, 0, 100);
    std::cout << "First Name: ";
    do { std::cin.getline(input, 100);
    } while (strlen(input) == 0);
    this->_firstName = input;
    return ;
}

void    Contact::setLastName(void) {
    char    input[100];
    
    memset(input, 0, 100);
    std::cout << "Last Name: ";
    do { std::cin.getline(input, 100);
    } while (strlen(input) == 0);
    this->_lastName = input;
    return ;
}

void    Contact::setNickName(void) {
    std::string input;
    
    std::cout << "NickName: ";
    std::cin >> input;
    this->_nickName = input;
    return ;
}

int    Contact::setPhoneNumber(void) {
    std::string input;
    int i = 0;
    
    std::cout << "Phone Number: ";
    std::cin >> input;
    while (input[i]) {
        if (isdigit(input[i])) {
            i++;
        } else {
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Insert right request." << std::endl;
            return (0);
        }
    }
    this->_phoneNumber = input;
    return (1);
}

void    Contact::setDarkestSecret(void) {
    char    input[500];
    
    memset(input, 0, 500);
    std::cout << "Darkest Secret: ";
    do { std::cin.getline(input, 500);
    } while (strlen(input) == 0);
    this->_darkestSecret = input;
    return ;
}

void    Contact::setStatus(void) {
    this->_status = 1;
    return ;
}
