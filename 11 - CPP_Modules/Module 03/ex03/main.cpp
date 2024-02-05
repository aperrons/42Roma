/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:46:02 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/07 04:54:44 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ClapTrap.hpp"
#include "headers/ScavTrap.hpp"
#include "headers/FragTrap.hpp"
#include "headers/DiamondTrap.hpp"

int	main(void) {

	DiamondTrap item("Fergy");

	std::cout << "Name: " << item.getName() << std::endl;
	std::cout << "HitPoints: " << item.getHitPoint() << std::endl;
	std::cout << "EnergyPoints: " << item.getEnergyPoint() << std::endl;
	std::cout << "AttackDamage: " << item.getAttackDamage() << std::endl;

	item.attack("Port");
	item.whoAmI();
	return (0);
}