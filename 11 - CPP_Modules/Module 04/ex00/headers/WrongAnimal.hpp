/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:00 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/05 00:04:35 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal &operator = (const WrongAnimal& src);
		virtual ~WrongAnimal(void);

		virtual std::string	getType(void) const;
		void makeSound(void) const;
		
		void	setType(std::string type);

	protected:
		std::string type;
};

#endif