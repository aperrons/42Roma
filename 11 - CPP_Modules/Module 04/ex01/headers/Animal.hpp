/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:00 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/05 02:21:53 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"

#include <iostream>

class Animal {

	public:
		Animal(void);
		Animal(const Animal& copy);
		Animal &operator = (const Animal& src);
		virtual ~Animal(void);

		virtual std::string	getType(void) const;
		virtual void makeSound(void) const;
		
		void		setType(std::string type);
		std::string getIdea(void);

	protected:
		Brain		*brain;
		std::string type;
};

#endif