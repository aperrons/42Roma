/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:49:03 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/07 05:32:47 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Character.hpp"


Character::Character(const std::string &name) : ICharacter(name) {
	for (int i = 0; i < 4; i++) {
		slots[i] = nullptr;
	}
	std::cout << "Character was builded" << std::endl;
}

Character::Character(const Character& copy) {
	for (int i = 0; i < 4; i++) {
		slots[i] = nullptr;
	}
	*this = copy;
	std::cout << "Character copy was builded" << std::endl;
}

Character &Character::operator = (const Character& src) {
	if (this == &src) {
		return *this;
	}
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] != nullptr) {
			delete this->slots[i];
			this->slots[i] = nullptr;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (src.slots[i] != nullptr) {
			this->slots[i] = src.slots[i]->clone();
		}
	}
	this->_name = src._name;
	return *this;
}

Character::~Character (void) {
	for (int i = 0; i < 4; i++)
		if (nullptr != this->slots[i]) {
			delete this->slots[i];
			this->slots[i] = nullptr;
		}
	std::cout << "Character was destroyed" << std::endl;
}

std::string const &ICharacter::getName(void) const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (slots[i] == nullptr) {
			slots[i] = m;
			return ;
		}
	}
	return ;
}

void Character::unequip(int idx) {
	slots[idx] = nullptr;
	return ;
}

void Character::use(int idx, ICharacter& target) {
	// std::cout << slots[idx] << std::endl;
	if (slots[idx] != nullptr) {
		// std::cout << "HERE" << std::endl;
		this->slots[idx]->use(target);
	}
	return ;
}

std::string const& Character::getName() const {
	return this->_name;
}