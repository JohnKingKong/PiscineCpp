/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.template.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:55:09 by anonymous         #+#    #+#             */
/*   Updated: 2022/12/05 11:14:45 by anonymous        ###   ########.fr       */
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

		class OutOfBoundAccessException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:
		T				*_array;
		unsigned int	_size;

};
	#include "Array.template.tpp"
