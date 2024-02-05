/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:46:02 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/07 02:10:45 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ClapTrap.hpp"
#include "headers/ScavTrap.hpp"

int	main(void) {

	ScavTrap thirdItem("Vetrus");

	std::cout << "Name: " << thirdItem.getName() << std::endl;
	std::cout << "HitPoints: " << thirdItem.getHitPoint() << std::endl;
	std::cout << "EnergyPoints: " << thirdItem.getEnergyPoint() << std::endl;
	std::cout << "AttackDamage: " << thirdItem.getAttackDamage() << std::endl;
	
	thirdItem.guardGate();
	thirdItem.attack("Trinky");

	return (0);
}