/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:16:31 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/30 11:53:28 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/FixedPointNumber.hpp"
#include "headers/Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point		a(0, 2);
	Point		b(3, 0);
	Point		c(3, 2);
	Point const	d(2, 1);
	Point const	e(2, 0);
	Point const	f(0, 2);

	std::cout << std::boolalpha << bsp(a, b, c, d) << std::endl;
	std::cout << std::boolalpha << bsp(a, b, c, e) << std::endl;
	std::cout << std::boolalpha << bsp(a, b, c, f) << std::endl;

	return (0);
}