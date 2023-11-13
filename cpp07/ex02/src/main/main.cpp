/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:21:57 by anonymous         #+#    #+#             */
/*   Updated: 2022/12/05 11:15:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.template.hpp"

int main() {

	Array<int>	_int(10);
	Array<float>	_float(10);
	Array<double>	_double;
	Array<char>		_char(10);
	Array<std::string>	_string(5);

	std::cout << std::fixed;
	std::cout.precision(2);

	try {
		std::cout << "Setting int 0 to 42 and int 9 to 69" << std::endl;
		_int[0] = 42;
		_int[9] = 69;
		std::cout << "int 0 = " << _int[0] << " and int 9 = " << _int[9];
		std::cout << " and int 5(not setted) = " << _int[5];
		std::cout << " and trying to access the 420" << std::endl;
		_int[420] = 21;
	}
	catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}

	try {
		std::cout << "Setting the float 0 to 42.00f and 9 to 69.69f" << std::endl;
		_float[0] = 42.00f;
		_float[9] = 69.69f;
		std::cout << "float 0 = " << _float[0] << "f and float 9 = " << _float[9];
		std::cout << "f and float 5(not setted) = " << _float[5];
		std::cout << "f and trying to access the 420" << std::endl;
		_float[420] = 420;
	}
	catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}

	try {
		std::cout << "Setting the double 0 to 42.00 and 9 to 69.69" << std::endl;
		_double[0] = 42.00;
		_double[9] = 69.69;
		std::cout << "double 0 = " << _double[0] << " and double 9 = " << _double[9];
		std::cout << " and double 5(not setted) = " << _double[5];
		std::cout << " and trying to access the 420" << std::endl;
		_double[420] = 420;
	}
	catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}

		try {
		std::cout << "Setting the char 0 to a and 9 to z" << std::endl;
		_char[0] = 'a';
		_char[9] = 'z';
		std::cout << "char 0 = " << _char[0] << " and char 9 = " << _char[9];
		std::cout << " and char 5(not setted) = " << _char[5];
		std::cout << " and trying to access the 420" << std::endl;
		_char[420] = 'p';
	}
	catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}

	try {
		std::cout << "setting the strings" << std::endl;
		_string[0] = "YOOOOOOOOOO";
		_string[4] = "PAOLO NONO";
		std::cout << "str 0 = " << _string[0] << " and str 4 = " << _string[4] << std::endl;
		std::cout << "str 2(not setted) = " << _string[2] << std::endl;
		_string[10] = "ohoh";
	}
	catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
	return 0;
}