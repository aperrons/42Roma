/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:26:08 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/05 00:17:57 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "WrongCat builded" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
	*this = copy;
	std::cout << "Copy WrongCat builded" << std::endl;
	return ;
}

WrongCat &WrongCat::operator = (const WrongCat& src) {
	if (this != &src) {
		return (*new(this) WrongCat());
	}
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destroyed" << std::endl;
}

std::string WrongCat::getType(void) const {
	return this->type;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Wrong Miao Miao" << std::endl;
}