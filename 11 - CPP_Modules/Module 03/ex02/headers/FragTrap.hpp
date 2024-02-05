/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:24:37 by aperrone          #+#    #+#             */
/*   Updated: 2023/06/07 02:25:51 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap& copy);
		FragTrap &operator = (const FragTrap &src);
		~FragTrap(void);

		void	highFivesGuys(void);
		
};

#endif