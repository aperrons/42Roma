/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:01:52 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/30 10:32:23 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/FixedPointNumber.hpp"
#include "../headers/Point.hpp"

Point::Point(void) : _x(0), _y(0) {
	return ;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	return ;
}

Point::Point(const Point& copy) {
	*this = copy;
	return ;
}

Point &Point::operator = (const Point &src) {
	if (this != &src) {
		return (*new(this) Point(src._x.toFloat(), src._y.toFloat()));
	}
	return (*this);
}

bool Point::operator == ( const Point &copy ) const{

	if (this->getX() == copy.getX() && this->getY() == this->getY())
		return (true);
	return (false);
}

Point::~Point(void) {
	return ;
}

float Point::getX(void) const {
	return this->_x.toFloat();
}

float Point::getY(void) const {
	return this->_y.toFloat();
}

std::ostream&	operator<<(std::ostream& stream, Point const &src) {
	stream << "x: " << src.getX() << "\ty: " << src.getY() << std::endl;
	return (stream);
}