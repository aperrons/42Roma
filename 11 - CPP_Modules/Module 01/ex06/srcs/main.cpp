/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:19:08 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 04:39:58 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Harl.hpp"

int main(int argc, char **argv) {
    Harl        harl;
    
    if(!(argc == 2)) {
        return (1);
    } else {
        std::cout << std::endl;
        harl.complain(argv[1]);
    }
    return 0;
}