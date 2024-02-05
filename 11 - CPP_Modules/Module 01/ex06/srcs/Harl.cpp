/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:19:03 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 04:42:41 by aperrone         ###   ########.fr       */
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
	
	while (i < 4 && levels[i].compare(level)) {
		i++;
	}
	switch (i) {
		case 0:
			(this->*func[i++])();
		case 1:
			(this->*func[i++])();
		case 2:
			(this->*func[i++])();
		case 3:
			(this->*func[i++])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << std::endl;
	}	
	return ;
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "Vorrei una banana!" << std::endl;
	std::cout << std::endl;
	return ;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Questa banana è troppo grossa perø!" << std::endl;
	std::cout << std::endl;
	return ;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Questa banana non puoi averla gratis, devi lavorare per ottenerla!" << std::endl;
	std::cout << std::endl;
	return ;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Inconcepibile." << std::endl;
	std::cout << std::endl;
	return ;
}