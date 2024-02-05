/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:12:11 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/07 02:09:04 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << this->getName() << " builded!" << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	*this = copy;
	return ;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &src) {
	if (this != &src) {
		return (*new(this) ScavTrap(src.getName()));
	}
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->getName() << " destroyed!" << std::endl;
	return ;
}

void ScavTrap::guardGate(void) {
	std::cout << this->getName() << " is now in Gate keeper mode." << std::endl;
}