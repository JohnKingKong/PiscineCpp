/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:58 by anonymous         #+#    #+#             */
/*   Updated: 2023/01/11 13:51:02 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
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

		operator int() const;
		operator double() const;
		operator float() const;
		operator char() const;

		std::string		getInput();


	private:
		std::string		_input;
		void			_checkInput();
		void			_setInput(std::string _input);
};

std::ostream&	operator<<(std::ostream & os, Conversion const & rhs);