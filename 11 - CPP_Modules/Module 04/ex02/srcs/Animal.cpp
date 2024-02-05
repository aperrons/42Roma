/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:26:08 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/05 06:29:43 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Animal.hpp"

Animal::Animal(void) : type("") {
	this->brain = new Brain();
	std::cout << "Animal builded" << std::endl;
}

Animal::Animal(const Animal &cpy) {
	*this = cpy;
	std::cout << "Copy Animal builded" << std::endl;
	return ;
}

Animal &Animal::operator = (const Animal &src) {
		if (this != &src) {
		this->type = src.type;
	}
	return *this;
}

Animal::~Animal(void) {
	delete this->brain;
	std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType(void) const {
	return this->type;
}

void	Animal::makeSound(void) const {
	std::cout << "Sound not in archive" << std::endl;
	return ;
}

void	Animal::setType(std::string type) {
	this->type = type;
	return ;
}

std::string Animal::getIdea(void) {
	return this->brain->printIdeas();
}