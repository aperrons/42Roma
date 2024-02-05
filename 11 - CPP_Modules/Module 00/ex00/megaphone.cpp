/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:56:19 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/04 20:56:21 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        int i = 0;
        while (argv[++i])
            for (int x = 0; argv[i][x]; x++) {
                std::cout << (char) toupper(argv[i][x]);
            }
    }
    std::cout << std::endl;
    return (0);
}