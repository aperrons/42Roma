/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:49:03 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/07 06:58:28 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource() {
	for (int i = 0; i < 4; i++) {
		set[i] = nullptr;
	}
	std::cout << "Default MateriaSource was builded" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	*this = copy;
	std::cout << "MateriaSource copy was builded" << std::endl;
}

MateriaSource &MateriaSource::operator = (const MateriaSource& src) {
	if (this == &src) {
		return *this;
	}
	*this = src;
	return *this;
}

MateriaSource::~MateriaSource (void) {
	std::cout << "MateriaSource was destroyed" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
		for (int i = 0; i < 4; i++) {
			if (set[i] == nullptr) {
				set[i] = m;
			return ;
		}
	}
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (!strcmp(set[i]->getType().c_str(), type.c_str())) {
			return this->set[i]->clone();
		}
	}
	return 0;
}