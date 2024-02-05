/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:16:23 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/06 15:28:36 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDPOINTNUMBER_HPP
#define FIXEDPOINTNUMBER_HPP

#include <iostream>

class Fixed {

    public:
        Fixed(void);
        Fixed(const Fixed& copy);
        Fixed &operator = (const Fixed& src);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        
    private:
        int                 _value;
        static const int    _fract_bits;
    
};

#endif