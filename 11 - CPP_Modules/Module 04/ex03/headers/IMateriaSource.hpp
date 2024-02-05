/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:48:58 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/07 02:00:48 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>

#include "AMateria.hpp"

class IMateriaSource {

	public:
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource& copy);
		IMateriaSource &operator = (const IMateriaSource& src);
		virtual ~IMateriaSource(void);

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;

	protected:
		AMateria *set[4];
};

#endif