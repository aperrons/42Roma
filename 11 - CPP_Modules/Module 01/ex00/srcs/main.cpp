/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:16:31 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 01:16:33 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Zombie.hpp"

int main(void) {
    Zombie zombie = Zombie("Astia");
    zombie.annunce();
    randomChump("Rubia");
    return (0);
}