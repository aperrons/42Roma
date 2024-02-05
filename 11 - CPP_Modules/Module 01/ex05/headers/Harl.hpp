/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:18:57 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 03:46:14 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {

	public:
		Harl(void);
		~Harl();

		void	complain(std::string level);

	private:
		typedef void(Harl::*to_func)(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};


#endif