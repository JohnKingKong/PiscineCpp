/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:58 by anonymous         #+#    #+#             */
/*   Updated: 2023/01/11 17:22:34 by jvigneau         ###   ########.fr       */
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
	int			_int;
	size_t		lenghtOfInt;

	try {
		if (this->_input.size() == 1)
			_int = static_cast<int>(this->_input[0]);
		else
			try {
				_int = std::stoi(this->_input, &lenghtOfInt, 10);
				if (lenghtOfInt != this->_input.size()) {
					std::cout << "Int: Impossible" << std::endl;
					return _int;
				}
			}
			catch (std::out_of_range & outOfRange){
				std::cout << "Int : Out of range" << std::endl;
				return _int;
			}
	}
	catch (std::invalid_argument & invalidArgument) {
		std::cout << "Int : Impossible" << std::endl;
		return _int;
	}
	std::cout << "Int : " << _int << std::endl;
	return (_int);
}

Conversion::operator double() const {
	double		_double;
	size_t		lenghtOfDouble;

	std::cout << std::fixed;
	std::cout.precision(2);
	try {
		_double = std::stod(this->_input, &lenghtOfDouble);
		if (lenghtOfDouble < this->_input.size() && this->_input != "nan" && this->_input != "nanf"
			&& this->_input != "inf" && this->_input != "inff") {
			std::cout << "Double: Impossible" <<std::endl;
			return _double;
		}
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
	float		_float;
	size_t		lenghtOfFloat;

	std::cout << std::fixed;
	std::cout.precision(2);
	try {
		_float = std::stof(this->_input, &lenghtOfFloat);
		if (lenghtOfFloat < this->_input.size() && this->_input != "nan" && this->_input != "nanf"
				&& this->_input != "inf" && this->_input != "inff") {
			std::cout << "Float: Impossible" << std::endl;
			return _float;
		}
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
	size_t	a;

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
			_char = std::stoi(this->_input, &a, 10);
			if (a < this->_input.size() && this->_input != "nan" && this->_input != "nanf"
					&& this->_input != "inf" && this->_input != "inff")
			if (_char > 127) {
				std::cout << "Char: Out Of Range" << std::endl;
				return _char;
			}
		}
		catch (std::invalid_argument & invalidArgument) {
			std::cout << "Char : Impossible" << std::endl;
			return _char;
		}
		catch (std::out_of_range & outOfRange) {
			std::cout << "Char : Out of Range" << std::endl;
			return _char;
		}
	}

	if (static_cast<int>(_char) < 0 || static_cast<int>(_char) > INT_MAX)
		std::cout << "Char : Impossible" << std::endl;
	else if (std::isprint(_char))
		std::cout << "Char : " << _char << std::endl;
	else
		std::cout << "Char : Non Printable" << std::endl;
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

