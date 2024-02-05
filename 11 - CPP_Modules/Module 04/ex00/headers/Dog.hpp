/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:00 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/04 23:46:58 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog: public Animal {

	public:
		Dog(void);
		Dog(const Dog& copy);
		Dog &operator = (const Dog& src);
		~Dog(void);

		std::string	getType(void) const;
		void 		makeSound(void) const;

	protected:
		std::string type;
};

#endif