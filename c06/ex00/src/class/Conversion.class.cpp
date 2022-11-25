/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:58 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/24 21:12:44 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.class.hpp"
#include <string>


Conversion::Conversion() {
	_error = true;
	_checkInput();
}

Conversion::Conversion(char c) {
	if (c || !c)
		throw (Exceptions::WrongInputException());
}

Conversion::Conversion(const std::string& input) {
	_error = false;
	_setInput(input);
	_checkInput();
}

Conversion::Conversion(const Conversion& other) {
	*this = other;
}

Conversion::~Conversion() {
}



Conversion::operator int() {
	int		_int;
	char*	cString;

	_int = static_cast<int>(std::strtol(this->_input.c_str(), &cString, 10));
	std::cout << "int = " << _int << std::endl;
	return (_int);
}

Conversion::operator double() {
	double	_double;
	char*	cString;

	std::cout << std::fixed;
	std::cout.precision(1);
	_double = (std::strtod(this->_input.c_str(), &cString));
	std::cout << "double = " << _double << std::endl;
	return (_double);
}

Conversion::operator float() {
	float	_float;
	char	*cString;

	std::cout << std::fixed;
	std::cout.precision(1);
	_float = (std::strtof(this->_input.c_str(), &cString));
	std::cout << "float = " << _float << "f" << std::endl;
	return (_float);
}

Conversion::operator char() {
	int		_char;
	char*	cString;

	_char = static_cast<char>(std::strtol(this->_input.c_str(), &cString, 10));
	std::cout << "char = " << _char << std::endl;
	return (_char);
}





Conversion& Conversion::operator=(Conversion const & rhs) {
	_setInput(rhs._input);
	// _setChar(rhs._char);
	// _setInt(rhs._int);
	// _setDouble(rhs._double);
	// _setFloat(rhs._float);
	_type = rhs._type;
	_error = rhs._error;
	return *this;
}








void		Conversion::_checkInput() {
	if (_input.empty())
		throw(Exceptions::WrongInputException());
}



// bool		Conversion::_checkPseudoLiteral() {
// 	if (_input == "nanf" || _input == "-inff" || _input == "+inff") {
// 		_input.erase(_input.end() - 1);
// 	}
// 	if (_input == "nan" || _input == "-inf" || _input == "+inf")
// 		return true;
// 	return false;
// }



// void		Conversion::_setType() {
// 	char	*tempValue;

// 	if (_input.length() == 1 && !std::isdigit(_input[0])) {
// 		_type = CHAR;
// 		_setChar(_input[0]);
// 	}
// 	else 	{
// 		if (_input.find('.') != std::string::npos || _checkPseudoLiteral()) {
// 			if (_input.find('.') != std::string::npos && _input[_input.length() - 1] == 'f') {
// 				_type = FLOAT;
// 				_input.erase(_input.end() - 1);
// 				_setFloat(std::strtof(_input.c_str(), &tempValue));
// 			}
// 			else {
// 				_type = DOUBLE;
// 				_setDouble(std::strtod(_input.c_str(), &tempValue));
// 			}
// 			if (*tempValue != '\0')
// 				_error = true;
// 		}
// 		else {
// 			_type = INT;
// 			_setInt(static_cast<int>(std::strtol(_input.c_str(), &tempValue, 10)));
// 			if  (*tempValue != '\0')
// 				_error = true;
// 		}
// 	}
// 	std::cout << "type = " << this->_type << " " << _char  << " " << _int << " " << " " << _double << " " << _float << std::endl;
// 	std::cout << "booool = " << _error << std::endl;
// }







// void		Conversion::_setChar(char _char) { this->_char = _char; }
// void		Conversion::_setInt(int _int) { this->_int = _int; }
// void		Conversion::_setDouble(double _double) { this->_double = _double; }
// void		Conversion::_setFloat(float _float) { this->_float = _float; }
void			Conversion::_setInput(std::string input) { this->_input = input; }
std::string		Conversion::getInput() { return this->_input; }

