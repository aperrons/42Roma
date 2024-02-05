/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:00:07 by aperrone          #+#    #+#             */
/*   Updated: 2023/07/05 02:15:35 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <cstring>

class Brain {

	public:
		Brain(void);
		Brain(const Brain& copy);
		Brain &operator = (const Brain& src);
		~Brain(void);

		void		setIdeas(std::string idea);
		std::string printIdeas(void) const;
		std::string ideas[100];
};

#endif