/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:00 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/04 23:52:03 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {

	public:
		Animal(void);
		Animal(const Animal& copy);
		Animal &operator = (const Animal& src);
		virtual ~Animal(void);

		virtual std::string	getType(void) const;
		virtual void makeSound(void) const;
		
		void	setType(std::string type);

	protected:
		std::string type;
};

#endif