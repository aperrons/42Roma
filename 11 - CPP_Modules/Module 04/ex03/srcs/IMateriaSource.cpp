/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:49:03 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/07 04:16:39 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void) {
	std::cout << "Default IMateriaSource was builded" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& copy) {
	*this = copy;
	std::cout << "IMateriaSource copy was builded" << std::endl;
}

IMateriaSource &IMateriaSource::operator = (const IMateriaSource& src) {
	if (this == &src) {
		return *this;
	}
	*this = src;
	return *this;
}

IMateriaSource::~IMateriaSource (void) {
	std::cout << "IMateriaSource was destroyed" << std::endl;
}
