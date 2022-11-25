/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:58 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/25 14:47:32 by jvigneau         ###   ########.fr       */
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

	try {
		_int = std::stoi(this->_input);
	}
	catch (std::invalid_argument & invalidArgument) {
		std::cout << "Int : Impossible" << std::endl;
		return _int;
	}
	catch (std::out_of_range & outOfRange){
		std::cout << "Int : Out of range" << std::endl;
		return _int;
	}
	std::cout << "Int : " << _int << std::endl;
	return (_int);
}

Conversion::operator double() const {
	double	_double;

	std::cout << std::fixed;
	std::cout.precision(2);
	try {
		_double = std::stod(this->_input);
	}
	catch (std::out_of_range & outOfRange){
		std::cout << "Double : Out of Range" << std::endl;
		return _double;
	}
	catch (std::invalid_argument & invalidArgument) {
		std::cout << "Double : Impossible" << std::endl;
		return _double;
	}
	std::cout << "Double : " << _double << std::endl;
	return (_double);
}

Conversion::operator float() const {
	float	_float;

	std::cout << std::fixed;
	std::cout.precision(2);
	try {
		_float = std::stof(this->_input);
	}
	catch (std::out_of_range & outOfRange){
		std::cout << "Float : Out of Range" << std::endl;
		return _float;
	}
	catch (std::invalid_argument & invalidArgument) {
		std::cout << "Float : Impossible" << std::endl;
		return _float;
	}
	std::cout << "Float : " << _float << "f" << std::endl;
	return (_float);
}

Conversion::operator char() const {
	char	_char;

	if (this->_input.length() == 1)  {
		try {
			_char = std::stoi(this->_input);
		}
		catch (std::invalid_argument & invalidArgument) {
			_char = static_cast<char>(this->_input[0]);
		}
	}

	else {
		try {
			_char = std::stoi(this->_input);
		}
		catch (std::invalid_argument & invalidArgument) {
			std::cout << "Char : Impossible" << std::endl;
			return _char;
		}
	}

	if (std::isprint(_char))
		std::cout << "Char : " << _char << std::endl;
	else
		std::cout << "Char : Impossible" << std::endl;
	return (_char);
}



/*------------Stream output overload------------*/


std::ostream& operator << (std::ostream &os, Conversion const & rhs) {
	char	_char = rhs;
	int		_int = rhs;
	double	_double = rhs;
	float	_float = rhs;

	if (_char && _int && _double && _float)
		return os;
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

