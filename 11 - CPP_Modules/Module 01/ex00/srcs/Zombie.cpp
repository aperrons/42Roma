/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:16:47 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 01:16:47 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/Zombie.hpp"

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
