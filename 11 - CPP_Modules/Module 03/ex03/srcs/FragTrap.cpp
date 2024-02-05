/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:26:36 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/07 03:36:03 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("") {
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << this->getName() << " builded!" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << this->getName() << " builded!" << std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	*this = copy;
	return ;
}

FragTrap &FragTrap::operator = (const FragTrap &src) {
	if (this != &src) {
		return (*new(this) FragTrap(src.getName()));
	}
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->getName() << " destroyed!" << std::endl;
	return ;
}

void FragTrap::highFivesGuys(void) {
	std::cout << this->getName() << " say: give me five!" << std::endl;
}