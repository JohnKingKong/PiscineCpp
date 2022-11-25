/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:58 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/24 20:38:10 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include "Colors.hpp" 
#include "Exceptions.class.hpp"

class Conversion {

	public:

		Conversion();
		Conversion(char c);
		Conversion(const std::string& input);
		Conversion(const Conversion& other);
		~Conversion();

		Conversion& operator=(Conversion const & rhs);

		operator int();
		operator double();
		operator float();
		operator char();

		std::string		getInput();

	private:
		enum Type {
			CHAR = 0,
			DOUBLE = 1,
			FLOAT = 2,
			INT = 3
		};

		std::string		_input;
		// char			_char;
		// int			_int;
		// double		_double;
		// float		_float;
		int				_type;
		bool			_error;

		void			_checkInput();
		// void			_setType();
		// void			_setChar(char _char);
		// void			_setInt(int _int);
		// void			_setDouble(double _double);
		// void			_setFloat(float _float);
		void			_setInput(std::string _input);
		// bool			_checkPseudoLiteral();


};
