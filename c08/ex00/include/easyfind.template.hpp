/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.template.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:01:20 by anonymous         #+#    #+#             */
/*   Updated: 2022/12/05 16:17:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>
#include <list>
#include <vector>


class NumberNotFoundException : public std::exception {
	public :
		virtual const char * what() const throw() {
			return "has NOT been found";
		}
};

template <typename T>
void	printContainer(T intContainer) {
	std::copy(intContainer.begin(), intContainer.end(),
		std::ostream_iterator<int>(std::cout, " "));
}

template <typename T>
void	easyfind(T intContainer, int intToFind) {
	T	temp = intContainer;
	if (std::find(temp.begin(), temp.end(), intToFind) != temp.end())
		std::cout << "has been found" << std::endl;
	else
		throw(NumberNotFoundException());
}

template <typename T>
void	populate(T *intContainer, int size) {
	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		intContainer->push_back(rand() % 500);
	}
}

template <typename T>
void	testMain(T intContainer){
	int size = rand() % 500;
	std::cout << std::endl << "The size of the int container is ";
	std::cout << size;
	std::cout << std::endl;
	populate(&intContainer, size);
	try {
		int intToFind = rand() % 200;
		std::cout << std::endl << "The int container is :" << std::endl << std::endl;
		printContainer(intContainer);
		std::cout << std::endl << std::endl;

		std::cout << "The number to find is ";
		std::cout << intToFind;
		std::cout << " and it ";
		easyfind(intContainer, intToFind);
	}
	catch (std::exception & exception) {
		std::cout << exception.what() << std::endl;
	}
}


