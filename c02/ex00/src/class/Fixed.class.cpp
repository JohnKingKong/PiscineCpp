/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:21 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/09 12:44:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Fixed.class.hpp"


Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	Fixed::setRawBits(0);
}
Fixed::Fixed(const Fixed& src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
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

Fixed& Fixed::operator=(Fixed const & e){
	std::cout << "Copy assignment operator called" << std::endl;
	Fixed::setRawBits(e.getRawBits());
	return (*this);
}


