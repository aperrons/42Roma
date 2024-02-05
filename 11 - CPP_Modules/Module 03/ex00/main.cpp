/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:46:02 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/06 20:16:59 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ClapTrap.hpp"

int	main(void) {

	ClapTrap firstItem("Elayah");
	ClapTrap secondItem("Gevova");

	std::cout << "Name: " << firstItem.getName() << std::endl;
	std::cout << "HitPoints: " << firstItem.getHitPoint() << std::endl;
	std::cout << "EnergyPoints: " << firstItem.getEnergyPoint() << std::endl;
	std::cout << "AttackDamage: " << firstItem.getAttackDamage() << std::endl;

	std::cout << std::endl;

	std::cout << "Name: " << secondItem.getName() << std::endl;
	std::cout << "HitPoints: " << secondItem.getHitPoint() << std::endl;
	std::cout << "EnergyPoints: " << secondItem.getEnergyPoint() << std::endl;
	std::cout << "AttackDamage: " << secondItem.getAttackDamage() << std::endl;

	std::cout << std::endl;

	firstItem.attack(secondItem.getName());
	secondItem.takeDamage(11);

	std::cout << std::endl;

	std::cout << "Name: " << firstItem.getName() << std::endl;
	std::cout << "HitPoints: " << firstItem.getHitPoint() << std::endl;
	std::cout << "EnergyPoints: " << firstItem.getEnergyPoint() << std::endl;
	std::cout << "AttackDamage: " << firstItem.getAttackDamage() << std::endl;

	std::cout << std::endl;

	std::cout << "Name: " << secondItem.getName() << std::endl;
	std::cout << "HitPoints: " << secondItem.getHitPoint() << std::endl;
	std::cout << "EnergyPoints: " << secondItem.getEnergyPoint() << std::endl;
	std::cout << "AttackDamage: " << secondItem.getAttackDamage() << std::endl;

	secondItem.beRepaired(1);

	std::cout << std::endl;

	std::cout << "Name: " << firstItem.getName() << std::endl;
	std::cout << "HitPoints: " << firstItem.getHitPoint() << std::endl;
	std::cout << "EnergyPoints: " << firstItem.getEnergyPoint() << std::endl;
	std::cout << "AttackDamage: " << firstItem.getAttackDamage() << std::endl;

	std::cout << std::endl;

	std::cout << "Name: " << secondItem.getName() << std::endl;
	std::cout << "HitPoints: " << secondItem.getHitPoint() << std::endl;
	std::cout << "EnergyPoints: " << secondItem.getEnergyPoint() << std::endl;
	std::cout << "AttackDamage: " << secondItem.getAttackDamage() << std::endl;

	std::cout << std::endl;

	secondItem.attack(firstItem.getName());
	return (0);
}