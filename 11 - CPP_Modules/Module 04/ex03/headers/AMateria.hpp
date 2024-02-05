/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:48:58 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/07 04:02:54 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

#include <iostream>

class ICharacter;

class AMateria {

	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria& copy);
		AMateria &operator = (const AMateria& src);
		virtual ~AMateria(void);

		std::string const &getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
		
	protected:
		std::string _type;
};

std::string toLow(std::string str);

#endif