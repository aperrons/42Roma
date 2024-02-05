/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:22:59 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/05 00:22:09 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Animal.hpp"
#include "headers/WrongAnimal.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"
#include "headers/WrongCat.hpp"

int main (void) {

	Animal *animal = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();
	WrongAnimal *wrongCat = new WrongCat();

	std::cout << animal->getType() << std::endl;
	animal->setType("Dog");
	std::cout << animal->getType() << std::endl;
	animal->makeSound();

	std::cout << dog->getType() << std::endl;
	dog->makeSound();

	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();


	delete dog;
	delete cat;
	delete wrongCat;
	return (0);
}
