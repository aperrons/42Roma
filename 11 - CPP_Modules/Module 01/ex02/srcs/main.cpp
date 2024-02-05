/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:17:41 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 01:17:42 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
    
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Address of string: " << &string  << std::endl;
    std::cout << "Address of stringPTR: " << &stringPTR  << std::endl;
    std::cout << "Address of stringREF: " << &stringREF  << std::endl;
    std::cout << "- - - - - - - - - - - - - -  -" << std::endl;
    std::cout << "String value: " << string << std::endl;
    std::cout << "Pointed by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Pointed by stringREF: " << stringREF << std::endl;


    return (0);
}