/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:33:44 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/30 11:48:57 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/FixedPointNumber.hpp"
#include "../headers/Point.hpp"

bool bsp(Point const A, Point const B, Point const C, Point const point) {

	float pa, a1, a2, a3;
	float px, x1, x2, x3, py, y1, y2, y3;

	if (point == A || point == B || point == C)
		return (false);

	px = point.getX();
	x1 = A.getX();
	x2 = B.getX();
	x3 = C.getX();

	py = point.getY();
	y1 = A.getY();
	y2 = B.getY();
	y3 = C.getY();

	pa = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
	a1 = abs((px * (y2 - y3) + x2 * (y3 - py) + x3 * (py - y2)) / 2);
	a2 = abs((x1 * (py - y3) + px * (y3 - y1) + x3 * (y1 - py)) / 2);
	a3 = abs((x1 * (y2 - py) + x2 * (py - y1) + px * (y1 - y2)) / 2);

	if (pa == (a1 + a2 + a3))
		return (true);
	return (false);
}