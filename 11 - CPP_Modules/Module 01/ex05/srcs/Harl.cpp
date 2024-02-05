/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:19:03 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 03:51:43 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Harl.hpp"

Harl::Harl(void) {
	return ;
}

Harl::~Harl() {
	return ;
}

void Harl::complain(std::string level) {
	
	int i = 0;
	std::string levels[]= {"DEBUG", "INFO", "WARNING", "ERROR"};
	to_func func[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error   
	};
	
	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4) {
		(this->*func[i])();
	} else if (level.compare("EXIT")) {
		std::cout << "Function not allowed." << std::endl;
	}
		
	return ;
}

void Harl::debug(void) {
	std::cout << "Vorrei una banana!" << std::endl;
	return ;
}

void Harl::info(void) {
	std::cout << "Questa banana è troppo grossa perø!" << std::endl;
	return ;
}

void Harl::warning(void) {
	std::cout << "Questa banana non puoi averla gratis, devi lavorare per ottenerla!" << std::endl;
	return ;
}

void Harl::error(void) {
	std::cout << "Inconcepibile." << std::endl;
	return ;
}