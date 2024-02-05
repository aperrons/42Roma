/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:49:03 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/07 04:30:46 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Ice.hpp"
#include "../headers/AMateria.hpp"

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Default Ice was builded" << std::endl;
	return;
}

Ice::Ice(const std::string &type) : AMateria(toLow(type)) {
	std::cout << "Ice was builded" << std::endl;
}

Ice::Ice(const Ice& copy) {
	*this = copy;
	std::cout << "Ice copy was builded" << std::endl;
}

Ice &Ice::operator = (const Ice& src) {
	if (this == &src) {
		return *this;
	}
	this->_type = src.getType();
	return *this;
}

Ice::~Ice (void) {
	std::cout << "Ice was destroyed" << std::endl;
}

std::string const &Ice::getType(void) const {
	return this->_type;
}

Ice* Ice::clone (void) const {
	return (new Ice());
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<  std::endl;
	return ;
}