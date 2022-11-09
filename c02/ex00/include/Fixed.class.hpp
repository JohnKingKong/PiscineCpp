/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:13:58 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/09 12:41:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
	public:

		Fixed();
		Fixed(const Fixed& src);
		~Fixed();

		Fixed& operator=(Fixed const & e);

		int			getRawBits()const ;
		void		setRawBits(int const raw);

	private:
		int					_FixedPointValue;
		int static const	_nbBitsForFixedPoint = 8;

};
