/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:21 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/09 15:58:27 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Fixed.class.hpp"


Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	Fixed::setRawBits(0);
}
Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

void		Fixed::setRawBits(int const raw){
	this->_FixedPointValue = raw;
}

int			Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_FixedPointValue);
}

Fixed& Fixed::operator=(Fixed const & rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	Fixed::setRawBits(rhs.getRawBits());
	return (*this);
}


