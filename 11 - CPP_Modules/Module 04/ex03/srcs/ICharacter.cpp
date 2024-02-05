/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:49:03 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/07 05:32:53 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ICharacter.hpp"

ICharacter::ICharacter(void) : _name("") {
	std::cout << "Default ICharacter was builded" << std::endl;
}

ICharacter::ICharacter(const std::string &name) : _name(name) {
	std::cout << "ICharacter was builded" << std::endl;
}

ICharacter::ICharacter(const ICharacter& copy) {
	*this = copy;
	std::cout << "ICharacter copy was builded" << std::endl;
}

ICharacter &ICharacter::operator = (const ICharacter& src) {
	if (this->_name == src._name) {
		return *this;
	}
	this->_name = src.getName();
	return *this;
}

ICharacter::~ICharacter (void) {
	// for (int i = 0; i < 4; i++)
	// 	if (nullptr != this->slots[i]) {
	// 		delete this->slots[i];
	// 		this->slots[i] = nullptr;
	// 	}
	std::cout << "ICharacter was destroyed" << std::endl;
}
