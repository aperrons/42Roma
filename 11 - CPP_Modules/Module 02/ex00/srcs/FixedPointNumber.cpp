/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:16:23 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/06 15:55:35 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/FixedPointNumber.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed(void) : _value(0) {
    std::cout << "Constructor Called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &copy) {
    *this = copy;
    std::cout << "Copy Constructor Called" << std::endl;
    return ;
}

Fixed &Fixed::operator =(const Fixed &src) {
    if (this != &src) {
        this->_value = src.getRawBits();
    }
    std::cout << "Copy Assign Constructor Called" << std::endl;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor Called" << std::endl; 
    return ;
}

int Fixed::getRawBits(void) const {
    std::cout << "Raw Bit Got" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "Raw Bit Setted" << std::endl;
    this->_value = raw;
    return ;
}