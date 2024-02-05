/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:48:08 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/07 05:22:40 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : _name(name) {
	this->FragTrap::setHitPoint(FragTrap::getHitPoint());
	this->ScavTrap::setEnergyPoint(ScavTrap::getEnergyPoint());
	this->FragTrap::setAttackDamage(FragTrap::getAttackDamage());
	ClapTrap::setName(name + "_clap_name");
	std::cout << "DiamondTrap " << this->getName() << " builded!" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) {
	*this = copy;
	return ;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &src) {
	if (this != &src) {
		return (*new(this) DiamondTrap(src.getName()));
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->getName() << " destroyed!" << std::endl;
	return ;
}

void	DiamondTrap::whoAmI(){
	std::cout << "Io sono " << this->_name << " ma anche " << ClapTrap::getName() << std::endl;
}