/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.template.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:55:09 by anonymous         #+#    #+#             */
/*   Updated: 2022/12/02 17:28:24 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T>

class Array {
	public:

		Array();
		Array(unsigned int size);
		Array(const Array& other);
		~Array();

		Array<T> & operator=(Array const & rhs);
		T & operator[](std::size_t size);

		T				*getArray() const;
		unsigned int	getSize() const;

	private:
		T				*_array;
		unsigned int	_size;

};
	#include "Array.template.tpp"
