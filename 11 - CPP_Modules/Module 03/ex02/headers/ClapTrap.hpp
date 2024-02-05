/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:43:47 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/07 01:58:58 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap &operator = (const ClapTrap &src);
		~ClapTrap(void);

		std::string				getName(void) const;
		unsigned int			getHitPoint(void) const;
		unsigned int			getEnergyPoint(void) const;
		unsigned int			getAttackDamage(void) const;

		void					setName(std::string name);
		void					setHitPoint(unsigned int hitPoint);
		void					setEnergyPoint(unsigned int energyPoint);
		void					setAttackDamage(unsigned int attackDamage);
			
		void					attack(const std::string& target);
		void					takeDamage(unsigned int amount);
		void					beRepaired(unsigned int amount);
		
	private:
		std::string				_name;
		unsigned int			_hitPoint;
		unsigned int			_energyPoint;
		unsigned int			_attackDamage;
};

#endif