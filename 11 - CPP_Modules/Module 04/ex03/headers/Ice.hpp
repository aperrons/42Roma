/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:48:58 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/07 04:31:45 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

#include <iostream>

class Ice : public AMateria {

	public:
		Ice(void);
		Ice(const std::string &type);
		Ice(const Ice& copy);
		Ice &operator = (const Ice& src);
		virtual ~Ice(void);

		std::string const &getType(void) const;
		virtual Ice* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif