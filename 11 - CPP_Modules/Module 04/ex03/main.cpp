/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:22:59 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/07 06:58:09 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/AMateria.hpp"
#include "headers/Ice.hpp"  
#include "headers/Cure.hpp"
#include "headers/ICharacter.hpp"
#include "headers/Character.hpp"
#include "headers/MateriaSource.hpp"

int main (void) {

	IMateriaSource* src = new MateriaSource();
	Ice *ice = new Ice();
	Cure *cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
    me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	delete ice;
	delete cure;
	return 0; 
}
