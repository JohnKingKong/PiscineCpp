
#include "Fixed.class.hpp"


/*----------------Constructors and Destructor---------------*/


Fixed::Fixed() {
	setRawBits(0);
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(int const intInput) {
	setRawBits(intInput << _nbBitsForFixedPoint);
	std::cout << "Int constructor called" << std::endl;
}


Fixed::Fixed(float const floatInput){
	setRawBits(static_cast<int>(roundf(floatInput * static_cast<float>(1 << _nbBitsForFixedPoint))));
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
	return (static_cast<float>(Fixed::getRawBits()) / (1 << _nbBitsForFixedPoint));
}

int			Fixed::toInt() const {
	return (Fixed::getRawBits() >> _nbBitsForFixedPoint);
}


/*--------------Operator overload----------------*/


Fixed& Fixed::operator = (Fixed const & rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	Fixed::setRawBits(rhs.getRawBits());
	return (*this);
}

std::ostream& operator<<(std::ostream &os, Fixed const & rhs) {
	os << rhs.toFloat();
	return os;
}