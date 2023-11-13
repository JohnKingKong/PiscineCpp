/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IterBase.template.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:14:12 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/26 14:25:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ArithmeticBase.template.hpp"

template<typename T>
void	iter(T *vector, unsigned int size, void (*fct)(T const &)) {
	for (unsigned int i = 0; i < size; i++)
		(*fct)(vector[i]);
}

template<typename T>
void	printContentArray(T const & content) {
	std::cout << "Content : " << content << std::endl;
}

template<typename T>
void	swapFirstAndLastContent(T *vector, unsigned int last) {
	::swap(vector[0], vector[last - 1]);
}
