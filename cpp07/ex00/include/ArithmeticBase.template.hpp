/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArithmeticBase.template.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:24:39 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/26 12:47:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void	swap(T & firstValue, T & secondValue) {
	T	tempValue;

	tempValue = firstValue;
	firstValue = secondValue;
	secondValue = tempValue;
}

template <typename T>
T	min(T const & firstValue, T const & secondValue) {
	if (firstValue < secondValue)
		return firstValue;
	return secondValue;
}

template <typename T>
T	max(T const & firstValue, T const & secondValue) {
	if (firstValue > secondValue)
		return firstValue;
	return secondValue;
}