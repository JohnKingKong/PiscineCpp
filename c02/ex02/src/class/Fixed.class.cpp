/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:01:49 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/09 18:19:38 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.class.hpp"


/*----------------Constructors and Destructor---------------*/


Fixed::Fixed() : _FixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(int const intInput) : _FixedPointValue(intInput << _nbBitsForFixedPoint) {
	std::cout << "Int constructor called" << std::endl;
}


Fixed::Fixed(float const floatInput){
	setRawBits((int)roundf(floatInput * (float)(1 << _nbBitsForFixedPoint)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}


/*-------------Member Functions-----------------*/


void		Fixed::setRawBits(int const raw){
	this->_FixedPointValue = raw;
}

int			Fixed::getRawBits() const {
	return (this->_FixedPointValue);
}

float		Fixed::toFloat() const {
	return ((float)Fixed::getRawBits() / (1 << _nbBitsForFixedPoint));
}

int			Fixed::toInt() const {
	return (Fixed::getRawBits() >> _nbBitsForFixedPoint);
}


/*--------------Operator overload----------------*/


Fixed&		Fixed::operator = (Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	Fixed::setRawBits(rhs.getRawBits());
	return (*this);
}


Fixed&		Fixed::operator + (Fixed const & rhs) {
	return (Fixed::toFloat() + rhs.toFloat());
}

Fixed&		Fixed::operator - (Fixed const & rhs) {
	return (Fixed::toFloat() - rhs.toFloat());
}

Fixed&		Fixed::operator * (Fixed const & rhs) {
	return (Fixed::toFloat() * rhs.toFloat());
}

Fixed&		Fixed::operator / (Fixed const & rhs) {
	return (Fixed::toFloat() / rhs.toFloat());
}


bool		Fixed::operator < (Fixed const & rhs) {
	return (Fixed::toFloat() < rhs.toFloat());
}

bool		Fixed::operator > (Fixed const & rhs) {
	return (Fixed::toFloat() > rhs.toFloat());
}

bool		Fixed::operator >= (Fixed const & rhs) {
	return (Fixed::toFloat() >= rhs.toFloat());
}

bool		Fixed::operator <= (Fixed const & rhs) {
	return (Fixed::toFloat() <= rhs.toFloat());
}

bool		Fixed::operator == (Fixed const & rhs) {
	return (Fixed::toFloat() == rhs.toFloat());
}

bool		Fixed::operator != (Fixed const & rhs) {
	return (Fixed::toFloat() != rhs.toFloat());
}


Fixed		Fixed::operator ++ (int) {
	Fixed	temp(*this);

	this->_FixedPointValue++;
	return (temp);
}

Fixed&		Fixed::operator ++ () {
	++_FixedPointValue;
	return (*this);
}

Fixed		Fixed::operator -- (int) {
	Fixed	temp(*this);

	this->_FixedPointValue--;
	return (temp);
}

Fixed&		Fixed::operator -- () {
	--_FixedPointValue;
	return (*this);
}
std::ostream& operator<<(std::ostream &os, Fixed const & rhs) {
	os << rhs.toFloat();
	return os;
}


Fixed& Fixed::min(Fixed const &firstNumber, Fixed const &seconNumber) {
	const Fixed *tempPtr;

	if (firstNumber < seconNumber)
		tempPtr = &firstNumber;
	else
		tempPtr = &seconNumber;
	return (Fixed&)(*tempPtr);
}

Fixed& Fixed::max(Fixed const &firstNumber, Fixed const &seconNumber) {
	const Fixed *tempPtr;

	if (firstNumber > seconNumber)
		tempPtr = &firstNumber;
	else
		tempPtr = &seconNumber;
	return (Fixed&)(*tempPtr);
}

Fixed& Fixed::min(Fixed &firstNumber, Fixed &seconNumber) {
	if (firstNumber < seconNumber)
		return (firstNumber);
	return (seconNumber);
}

Fixed& Fixed::max(Fixed &firstNumber, Fixed &seconNumber) {
	if (firstNumber > seconNumber)
		return (firstNumber);
	return (seconNumber);
}
