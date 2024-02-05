/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:01:46 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/30 10:31:57 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point {

	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(float x, float y);
		Point(const Point& copy);
		Point &operator = (const Point &src);
		bool operator == ( const Point &copy ) const;
		~Point(void);

		float getX(void) const;
		float getY(void) const;
};

std::ostream&	operator << (std::ostream& stream, Point const &src);

#endif