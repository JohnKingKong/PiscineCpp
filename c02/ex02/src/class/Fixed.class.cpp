/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:01:49 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/16 14:03:58 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.class.hpp"


/*----------------Constructors and Destructor---------------*/


Fixed::Fixed() : _FixedPointValue(0) {
}


Fixed::Fixed(int const intInput) : _FixedPointValue(intInput << _nbBitsForFixedPoint) {
}


Fixed::Fixed(float const floatInput){
	setRawBits((int)roundf(floatInput * (float)(1 << _nbBitsForFixedPoint)));
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed(){
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



/*---------------Non-Member Functions------------------*/


Fixed &		Fixed::min(Fixed const &firstNumber, Fixed const &secondNumber) {
	const Fixed		*tempInstance;

	if (firstNumber < secondNumber)
		tempInstance = &firstNumber;
	else
		tempInstance = &secondNumber;
	return ((Fixed &)(*tempInstance));
}

Fixed &		Fixed::min(Fixed &firstNumber, Fixed &secondNumber) {
	if (firstNumber < secondNumber)
		return (firstNumber);
	return (secondNumber);
}

Fixed &		Fixed::max(Fixed const &firstNumber, Fixed const &secondNumber) {
	const Fixed		*tempInstance;

	if (firstNumber > secondNumber)
		tempInstance = &firstNumber;
	else
		tempInstance = &secondNumber;
	return ((Fixed &)(*tempInstance));
}

Fixed &		Fixed::max(Fixed &firstNumber, Fixed &secondNumber) {
	if (firstNumber > secondNumber)
		return (firstNumber);
	return (secondNumber);
}



/*-----Assignation operator overload----------------*/


Fixed&		Fixed::operator = (Fixed const & rhs) {
	Fixed::setRawBits(rhs.getRawBits());
	return (*this);
}



/*------------Comparative operator overload-------------*/


bool		Fixed::operator > (Fixed const & rhs) const {
		return (Fixed::toFloat() > rhs.toFloat());
}

bool		Fixed::operator < (Fixed const & rhs) const {
		return (Fixed::toFloat() < rhs.toFloat());
}

bool		Fixed::operator >= (Fixed const & rhs) const {
		return (Fixed::toFloat() >= rhs.toFloat());
}

bool		Fixed::operator <= (Fixed const & rhs) const {
		return (Fixed::toFloat() <= rhs.toFloat());
}

bool		Fixed::operator == (Fixed const & rhs) const {
		return (Fixed::toFloat() == rhs.toFloat());
}

bool		Fixed::operator != (Fixed const & rhs) const {
		return (Fixed::toFloat() != rhs.toFloat());
}



/*----------Arithmetic operator overlaod----------*/



Fixed		Fixed::operator + (Fixed const & rhs) const {
	return (Fixed(Fixed::toFloat() + rhs.toFloat()));
}

Fixed		Fixed::operator - (Fixed const & rhs) const {
	return (Fixed(Fixed::toFloat() - rhs.toFloat()));
}

Fixed		Fixed::operator * (Fixed const & rhs) const {
	return (Fixed(Fixed::toFloat() * rhs.toFloat()));
}

Fixed		Fixed::operator / (Fixed const & rhs) const {
	return (Fixed(Fixed::toFloat() / rhs.toFloat()));
}



/*---------Incrementor and Decrmentor operator overload-------*/


Fixed		Fixed::operator ++ (int) {
	Fixed	tempInstance = *this;

	tempInstance._FixedPointValue++;
	return (tempInstance);
}

Fixed &		Fixed::operator ++() {
	++_FixedPointValue;
	return (*this);
}

Fixed		Fixed::operator -- (int) {
	Fixed	tempInstance(*this);

	this->_FixedPointValue--;
	return(tempInstance);
}

Fixed &		Fixed::operator -- () {
	--_FixedPointValue;
	return (*this);
}



/*------------OStream operator overload--------------*/


std::ostream& operator<<(std::ostream &os, Fixed const & rhs) {
	os << rhs.toFloat();
	return os;
}
