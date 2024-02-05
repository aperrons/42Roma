/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:00:04 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/05 02:25:03 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Brain.hpp"

Brain::Brain(void) {
	memset(this->ideas, 0, 100);
	std::cout << "Now you have a brain, maybe" << std::endl;
}

Brain::Brain(const Brain& copy) {
	*this = copy;
	std::cout << "Now you have a brain of another" << std::endl;
}

Brain &Brain::operator = (const Brain& src) {
	if (this != &src) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain erased" << std::endl;
}

void Brain::setIdeas(std::string idea) {
	if (strlen(idea.c_str()) > 100) {
		std::cout << "Idea too big for this storage" << std::endl;
	} else {
		for (size_t i = 0; i < strlen(idea.c_str()); i++) {
			this->ideas[0].assign(idea);
		}
	}
}

std::string Brain::printIdeas(void) const {
	return this->ideas->c_str();
}