/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:18:14 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 01:18:14 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	this->_weapon = NULL;
	return ;
}

HumanB::~HumanB() {
	return ;
}

std::string HumanB::getName(void) const {
	return this->_name;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
	return;
}

void HumanB::attack() {
	std::cout << this->getName() << " attacks with their " << this->_weapon->getType() << std::endl;
}