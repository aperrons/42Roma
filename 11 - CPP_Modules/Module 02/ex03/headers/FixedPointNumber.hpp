/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:16:23 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/29 07:23:03 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDPOINTNUMBER_HPP
#define FIXEDPOINTNUMBER_HPP

#include <iostream>
#include <cmath>

class Fixed {

    public:
        Fixed(void);
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed& copy);
        ~Fixed(void);

        Fixed &operator = (const Fixed& src);

        bool operator > (const Fixed& src) const;
        bool operator < (const Fixed& src) const;
        bool operator >= (const Fixed& src) const;
        bool operator <= (const Fixed& src) const;
        bool operator == (const Fixed& src) const;
        bool operator != (const Fixed& src) const;

        Fixed operator + (const Fixed& src);
        Fixed operator - (const Fixed& src);
        Fixed operator * (const Fixed& src);
        Fixed operator / (const Fixed& src);

        Fixed &operator ++ ();
        Fixed operator ++ (int);
		Fixed &operator -- ();
		Fixed operator -- (int);

        static Fixed& min(Fixed& x, Fixed& y);
        static Fixed const& min(const Fixed& x, const Fixed& y);
        static Fixed& max(Fixed& x, Fixed& y);
        static Fixed const& max(const Fixed& x, const Fixed& y);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        
    private:
        int                 _value;
        static const int    _fract_bits;  
};

std::ostream &operator << (std::ostream& stream, const Fixed& src);

#endif