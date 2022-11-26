/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.template.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:55:09 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/26 15:07:47 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>

class Array {
	public:

		Array();
		Array(const Array& other);
		~Array();

		Array& operator=(Array const & rhs);

	private:
		T				_array;
		unsigned int	_size;

};
