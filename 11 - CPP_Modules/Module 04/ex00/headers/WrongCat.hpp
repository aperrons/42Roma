/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:00 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/05 00:08:17 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat: public WrongAnimal {

	public:
		WrongCat(void);
		WrongCat(const WrongCat& copy);
		WrongCat &operator = (const WrongCat& src);
		~WrongCat(void);

		std::string	getType(void) const;
		void 		makeSound(void) const;

	protected:
		std::string type;
};

#endif