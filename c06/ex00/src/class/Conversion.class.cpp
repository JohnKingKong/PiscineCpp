/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:58 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/25 13:32:19 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.class.hpp"
#include <string>

/*---------Constructors and Destructors---------*/


Conversion::Conversion() {
	throw (Exceptions::WrongInputException());
}

Conversion::Conversion(char c) {
	if (c || !c)
		throw (Exceptions::WrongInputException());
}

Conversion::Conversion(const std::string& input) {
	_setInput(input);
	_checkInput();
}

Conversion::Conversion(const Conversion& other) {
	*this = other;
}

Conversion::~Conversion() {
}



/*---------Assignation operator overload---------*/


Conversion& Conversion::operator=(Conversion const & rhs) {
	_setInput(rhs._input);
	return *this;
}



/*------------Cast operators overload------------*/


Conversion::operator int() const {
	int		_int;
	char*	cString;

	std::cout << std::fixed;
	std::cout.precision(2);
	try {
		_int = (std::strtol(this->_input.c_str(), &cString, 10));
	}
	catch (std::invalid_argument & invalidArgument) {
		std::cout<<"oho invalid argument for int" << std::endl;
		_int = 0;
	}
	catch (std::out_of_range & outOfRange){
		std::cout<<"oho out of range for int"<<std::endl;
		_int = 0;
	}
	return static_cast<int>(_int);
}

Conversion::operator double() const {
	double	_double;
	char*	cString;

	std::cout << std::fixed;
	std::cout.precision(2);
	try {
		_double = (std::strtod(this->_input.c_str(), &cString));
	}
	catch (std::out_of_range & outOfRange){
		std::cout<<"oho out of range for double"<<std::endl;
		_double = 0;
	}
	catch (std::invalid_argument & invalidArgument) {
		std::cout<<"oho invalid argument for double" << std::endl;
		_double = 0;
	}
	return static_cast<double>(_double);
}

Conversion::operator float() const {
	float	_float;
	char	*cString;

	std::cout << std::fixed;
	std::cout.precision(	2);
	try {
		_float = (std::strtof(this->_input.c_str(), &cString));
	}
	catch (std::out_of_range & outOfRange){
		std::cout<<"oho out of range for float"<<std::endl;
		_float = 0;
	}
	catch (std::invalid_argument & invalidArgument) {
		std::cout<<"oho invalid argument for float" << std::endl;
	_float = 0;
	}
	return static_cast<float>(_float);
}

Conversion::operator char() const {
	char	_char;
	char*	cString;


	try {
		_char = std::strtol(this->_input.c_str(), &cString, 10);
	}
	catch (std::invalid_argument & invalidArgument) {
		_char = static_cast<char>(this->_input[0]);
	}
	return static_cast<char>(_char);
}



/*------------Stream output overload------------*/


std::ostream& operator << (std::ostream &os, Conversion const & rhs) {
	char	_char = rhs;
	int		_int = rhs;
	double	_double = rhs;
	float	_float = rhs;

	os << "char : " << _char << ";" << std::endl;
	os << "int : " << _int << ";" << std::endl;
	os << "double : " << _double << ";" << std::endl;
	os << "float : " << _float << "f;" << std::endl;
	return os;
}


/*-----------Public member functions------------*/


std::string		Conversion::getInput() { return this->_input; }



/*-----------Private member functions------------*/


void			Conversion::_setInput(std::string input) { this->_input = input; }

void		Conversion::_checkInput() {
	if (_input.empty())
		throw(Exceptions::WrongInputException());
}

