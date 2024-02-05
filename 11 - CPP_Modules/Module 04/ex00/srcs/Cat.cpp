/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:26:08 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/04 23:49:33 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Cat.hpp"

Cat::Cat(void) : Animal() {
	this->type = "Cat";
	std::cout << "Cat builded" << std::endl;
}

Cat::Cat(const Cat &copy) {
	*this = copy;
	std::cout << "Copy Cat builded" << std::endl;
	return ;
}

Cat &Cat::operator = (const Cat& src) {
	if (this != &src) {
		return (*new(this) Cat());
	}
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat destroyed" << std::endl;
}

std::string Cat::getType(void) const {
	return this->type;
}

void	Cat::makeSound(void) const {
	std::cout << "Miao Miao" << std::endl;
}