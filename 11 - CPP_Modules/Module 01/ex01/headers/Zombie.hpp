/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:17:00 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 01:17:01 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie(void);

        void    annunce(void);
        void    setName(std::string name);

    private:
        std::string _name;
};
    
    Zombie  *zombieHorde(int N, std::string name);
    Zombie  *newZombie(std::string name);
    void    randomChump(std::string name);

#endif