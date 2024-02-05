/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:26:08 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/04 23:47:36 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Dog.hpp"

Dog::Dog(void) : Animal() {
	this->type = "Dog";
	std::cout << "Dog builded" << std::endl;
}

Dog::Dog(const Dog &copy) {
	*this = copy;
	std::cout << "Copy Dog builded" << std::endl;
	return ;
}

Dog &Dog::operator = (const Dog& src) {
	if (this != &src) {
		return (*new(this) Dog());
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog destroyed" << std::endl;
}

std::string Dog::getType(void) const {
	return this->type;
}

void	Dog::makeSound(void) const {
	std::cout << "Bau Bau" << std::endl;
}