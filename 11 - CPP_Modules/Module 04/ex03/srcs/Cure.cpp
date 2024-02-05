/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:49:03 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/07 04:30:58 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Default Cure was builded" << std::endl;
	return;
}

Cure::Cure(const std::string &type) : AMateria(toLow(type)) {
	std::cout << "Cure was builded" << std::endl;
}

Cure::Cure(const Cure& copy) {
	*this = copy;
	std::cout << "Cure copy was builded" << std::endl;
}

Cure &Cure::operator = (const Cure& src) {
	if (this == &src) {
		return *this;
	}
	this->_type = src.getType();
	return *this;
}

Cure::~Cure (void) {
	std::cout << "Cure was destroyed" << std::endl;
}

std::string const &Cure::getType(void) const {
	return this->_type;
}

Cure* Cure::clone (void) const {
	return (new Cure());
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" <<  std::endl;
	return ;
}