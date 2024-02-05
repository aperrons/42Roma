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
    return ;
}

Fixed::Fixed(const int n) : _value(n << _fract_bits) {
    return ;
}

Fixed::Fixed(const float n) : _value((int)(roundf(n * (1 << _fract_bits)))) {
    return ;
}

Fixed::Fixed(const Fixed &copy) {
    *this = copy;
    return ;
}

Fixed::~Fixed() {
    return ;
}

Fixed &Fixed::operator = (const Fixed &src) {
    if (this != &src) {
        this->_value = src.getRawBits();
    }
    return *this;
}

bool Fixed::operator > (const Fixed& src) const {
    return (this->_value > src._value);
}

bool Fixed::operator < (const Fixed& src) const {
    return (this->_value < src._value);
}

bool Fixed::operator >= (const Fixed& src) const {
    return (this->_value >= src._value);
}

bool Fixed::operator <= (const Fixed& src) const {
    return (this->_value <= src._value);
}

bool Fixed::operator == (const Fixed& src) const {
    return (this->_value == src._value);
}

bool Fixed::operator != (const Fixed& src) const {
    return (this->_value != src._value);
}

Fixed Fixed::operator + (const Fixed& src) {
    Fixed result(*this);

    result.setRawBits(this->getRawBits() + src.getRawBits());
    return (result);
}

Fixed Fixed::operator - (const Fixed& src) {
    Fixed result(*this);

    result.setRawBits(this->getRawBits() - src.getRawBits());
    return (result);
}

Fixed Fixed::operator * (const Fixed& src) {
    Fixed   result(*this);
    long    hBit;
    long    lBit;

    hBit = (long)this->getRawBits();
    lBit = (long)src.getRawBits();

    result.setRawBits((hBit * lBit) / (1 << Fixed::_fract_bits));
    return (result);
}

Fixed Fixed::operator / (const Fixed& src) {
    Fixed result(*this);

    result.setRawBits(this->getRawBits() / src.getRawBits());
    return (result);
}

Fixed &Fixed::operator ++ (){
	this->_value++;
	return (*this);
}

Fixed Fixed::operator ++ (int) {
	Fixed temp(*this);

	++this->_value;
	return (temp);
}

Fixed &Fixed::operator -- (){
	this->_value--;
	return (*this);
}

Fixed Fixed::operator -- (int) {
	Fixed temp(*this);

	--this->_value;
	return (temp);
}

Fixed &Fixed::min(Fixed& x, Fixed& y) {
    return (x < y ? x : y);
}

Fixed const &Fixed::min(const Fixed& x, const Fixed& y) {
    return (x < y ? x : y);
}

Fixed &Fixed::max(Fixed& x, Fixed& y) {
    return (x > y ? x : y);
}

Fixed const &Fixed::max(const Fixed& x, const Fixed& y) {
    return (x > y ? x : y);
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
    return ;
}

float Fixed::toFloat(void) const {
    return ((float)this->_value / (float)(1 << this->_fract_bits));
}

int Fixed::toInt(void) const {
    return (this->_value >> this->_fract_bits);
}

std::ostream &operator << (std::ostream& stream, const Fixed& src) {
    stream << src.toFloat();
    return (stream);
}