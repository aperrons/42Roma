/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:22:59 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/05 02:41:36 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Animal.hpp"
#include "headers/WrongAnimal.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"
#include "headers/WrongCat.hpp"
#include "headers/Brain.hpp"

int main (void) {

	Animal *cluster[8];

	for (unsigned long i = 0; i < (sizeof(cluster) / sizeof(cluster[0])) / 2; i++) {
		cluster[i] = new Dog();
	}
	for (unsigned long i = (sizeof(cluster) / sizeof(cluster[0])) / 2; i < (sizeof(cluster) / sizeof(cluster[0])); i++) {
		cluster[i] = new Cat();
	}
	for (unsigned long i = 0; i < (sizeof(cluster) / sizeof(cluster[0])); i++) {
		std::cout << cluster[i]->getIdea() << std::endl;
	}
	for (unsigned long i = 0; i < (sizeof(cluster) / sizeof(cluster[0])); i++) {
		delete cluster[i];
	}

	return (0);
}
