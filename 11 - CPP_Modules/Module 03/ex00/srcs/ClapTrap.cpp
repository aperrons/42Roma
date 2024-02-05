/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:43:54 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/07 01:54:30 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name) {
	this->_hitPoint = 10;
	this->_energyPoint = 10;
	this->_attackDamage = 0;
	std::cout << this->getName() << " builded!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	*this = copy;
	return ;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &src) {
	if (this != &src) {
		return (*new(this) ClapTrap(src.getName()));
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << this->getName() << " destroyed!" << std::endl;
	return ;
}

std::string	ClapTrap::getName(void) const {
	return this->_name;
}

unsigned int	ClapTrap::getHitPoint(void) const {
	return this->_hitPoint;
}

unsigned int	ClapTrap::getEnergyPoint(void) const {
	return this->_energyPoint;
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return this->_attackDamage;
}

void	ClapTrap::setName(std::string name) {
	this->_name = name;
	return ;
}

void	ClapTrap::setHitPoint(unsigned int hitPoint) {
	this->_hitPoint = hitPoint;
	return ;
}

void	ClapTrap::setEnergyPoint(unsigned int energyPoint) {
	this->_energyPoint = energyPoint;
	return ;
}

void	ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->_attackDamage = attackDamage;
	return ;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_hitPoint > 0 && this->_energyPoint > 0) {
		std::cout << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->_energyPoint--;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > this->_hitPoint) {
		this->_hitPoint = 0;
	} else {
		this->_hitPoint -= amount;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoint > 0 && this->_energyPoint > 0) {
		this->_hitPoint += amount;
		this->_energyPoint--;
	}
	return ;
}