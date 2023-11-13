/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:23:01 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/26 14:52:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IterBase.template.hpp"

int main() {

	std::cout << std::fixed;
	std::cout.precision(2);
	int		intArray[5] = { 42, 24, 69, 420, 500 };

	iter<int>(intArray, 5, printContentArray);
	std::cout << "swapping the first and last element of the array" << std::endl;
	swapFirstAndLastContent(intArray, 5);
	iter<int>(intArray, 5, printContentArray);
	std::cout << std::endl;
	char	charArray[10] = "Allo Bro!";
	iter<char>(charArray, 9, printContentArray);
	std::cout << "swapping the first and last element of the array" << std::endl;
	swapFirstAndLastContent(charArray, 10);
	iter<char>(charArray, 10, printContentArray);
	std::cout << std::endl;
	float	floatArray[3] = { 4.20f, 69.0f, 100.42f };
	iter(floatArray, 3, printContentArray);
	std::cout << "swapping the first and last element of the array" << std::endl;
	swapFirstAndLastContent(floatArray, 3);
	iter(floatArray, 3, printContentArray);
	return 0;
}