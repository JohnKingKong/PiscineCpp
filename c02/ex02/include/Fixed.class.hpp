/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:01:49 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/12 15:24:52 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	public:


/*-------------Constructors and Destructor---------------*/

		Fixed();
		Fixed(int const intInput);
		Fixed(float const floatInput);
		Fixed(const Fixed& other);
		~Fixed();

/*---------------Operators overload----------------*/

		Fixed& operator = (Fixed const & rhs);

		bool		operator > (Fixed const & rhs) const;
		bool		operator < (Fixed const & rhs) const;
		bool		operator >= (Fixed const & rhs) const;
		bool		operator <= (Fixed const & rhs) const;
		bool		operator == (Fixed const & rhs) const;
		bool		operator != (Fixed const & rhs) const;

		Fixed		operator + (Fixed const & rhs) const;
		Fixed		operator - (Fixed const & rhs) const;
		Fixed		operator * (Fixed const & rhs) const;
		Fixed		operator / (Fixed const & rhs) const;

		Fixed		operator ++ (int);
		Fixed&		operator ++ ();
		Fixed		operator -- (int);
		Fixed&		operator -- ();

/*----------------Member Functions----------------------*/

		int			getRawBits()const ;
		void		setRawBits(int const raw);
		float		toFloat() const;
		int			toInt() const;


/*--------------Non Member Function-------------------*/

		static Fixed&		min(Fixed const &firstNumber, Fixed const &secondNumber);
		static Fixed&		min(Fixed &firstNumber, Fixed &secondNumber);
		static Fixed&		max(Fixed const &firstNumber, Fixed const &secondNumber);
		static Fixed&		max(Fixed &firstNumber, Fixed &secondNumber);

	private:

		int					_FixedPointValue;
		int static const	_nbBitsForFixedPoint = 8;

};

	std::ostream& operator<<(std::ostream &os, Fixed const & rhs);