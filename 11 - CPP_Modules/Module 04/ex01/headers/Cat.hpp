/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:00 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/04 23:49:08 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat: public Animal {

	public:
		Cat(void);
		Cat(const Cat& copy);
		Cat &operator = (const Cat& src);
		~Cat(void);

		std::string	getType(void) const;
		void 		makeSound(void) const;

	protected:
		std::string type;
};

#endif