/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:53:39 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/23 17:01:33 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Colors.hpp"

class Exceptions {
	public:
		class WrongInputException : public std::exception {
			public:
				virtual const char* what() const throw();
	};

};