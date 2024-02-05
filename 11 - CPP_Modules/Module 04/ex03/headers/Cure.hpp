/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:48:58 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/05 10:24:09 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

#include <iostream>

class Cure : public AMateria {

	public:
		Cure(void);
		Cure(const std::string &type);
		Cure(const Cure& copy);
		Cure &operator = (const Cure& src);
		virtual ~Cure(void);

		std::string const &getType(void) const;
		virtual Cure* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif