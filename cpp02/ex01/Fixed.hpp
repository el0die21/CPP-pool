/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:00:50 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/25 16:46:27 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
	Fixed(void);
	Fixed(const int fixed_point);
	Fixed(const float fixed_point);
	Fixed (const Fixed &other);
	Fixed &operator = (const Fixed &other);
	~Fixed(void);
	
	int	getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat( void ) const;
	int toInt( void ) const;

	private:
	int	_fixedValue;
	static const int _fractBits = 8;	
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif