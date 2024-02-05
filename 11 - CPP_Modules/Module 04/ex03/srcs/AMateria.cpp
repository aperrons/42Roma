/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:49:03 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/07 05:25:55 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AMateria.hpp"

AMateria::AMateria(void) : _type("") {
	std::cout << "Default AMateria was builded" << std::endl;
	return;
}

AMateria::AMateria(const std::string &type) : _type(type) {
	std::cout << "AMateria was builded" << std::endl;
}

AMateria::AMateria(const AMateria& copy) {
	this->_type = copy.getType();
	std::cout << "AMateria copy was builded" << std::endl;
}

AMateria &AMateria::operator = (const AMateria& src) {
	if (this == &src) {
		return *this;
	}
	this->_type = src.getType();
	return *this;
}

AMateria::~AMateria (void) {
	std::cout << "AMateria was destroyed" << std::endl;
}

std::string const &AMateria::getType(void) const {
	return this->_type;
}

std::string toLow(std::string str) {
	std::string low;

	low = str;
	low[0] = tolower(low[0]);
	return low;
}

void	AMateria::use(ICharacter& target) {
	(void) target;
	return ;
}