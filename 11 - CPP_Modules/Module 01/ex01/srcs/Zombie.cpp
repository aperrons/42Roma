/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:17:19 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 01:17:20 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/Zombie.hpp"

Zombie::Zombie(void) {
    return ;
}

Zombie::Zombie(std::string name) : _name(name) {
    return ;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->_name << " destroyed." << std::endl;
    return ;
}

void    Zombie::annunce() {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name) {
    this->_name = name;
}
