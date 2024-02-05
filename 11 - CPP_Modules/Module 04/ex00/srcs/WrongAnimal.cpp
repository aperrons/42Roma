/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:26:08 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/05 00:03:43 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("") {
	std::cout << "WrongAnimal builded" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) {
	*this = cpy;
	std::cout << "Copy WrongAnimal builded" << std::endl;
	return ;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &src) {
		if (this != &src) {
		return (*new(this) WrongAnimal());
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destroyed" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Sound not in archive" << std::endl;
	return ;
}

void	WrongAnimal::setType(std::string type) {
	this->type = type;
	return ;
}