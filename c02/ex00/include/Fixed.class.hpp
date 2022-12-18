/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:13:58 by anonymous         #+#    #+#             */
/*   Updated: 2022/12/10 14:45:19 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
	public:

		Fixed();
		Fixed(const Fixed& other);
		~Fixed();

		Fixed& operator=(Fixed const & rhs);

		int			getRawBits()const ;
		void		setRawBits(int const raw);

	private:
		int					_FixedPointValue;
		int static const	_nbBitsForFixedPoint = 8;

};
