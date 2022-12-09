/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.template.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:01:20 by anonymous         #+#    #+#             */
/*   Updated: 2022/12/06 13:45:22 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>
#include <list>
#include <vector>
#include <array>
#include <cstdlib>
#include <stack>
#include <unistd.h>
#include <forward_list>


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
	if (std::find(intContainer.begin(), intContainer.end(), intToFind) != intContainer.end())
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
void	testMain(T intContainer, int size){
	
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

template <typename T>
void	testArray(T intContainer, int size) {
	try {
		for(int i = 0; i < size; i++) { 
			intContainer[i] = rand() % 500;
		};
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

template <typename T>
void	testForwardList(T intContainer, int size){
	
	for (int i = 0; i < size; i++) {
		intContainer.push_front(rand() % 500);
	}
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

// template<typename T>
// struct Unprotect : public T 
// {
// 	typedef void (T::*undelyingContainerPtr)();
// 	static undelyingContainerPtr getUnderlyingPtr() {
// 		return &Unprotect::undelyingContainer;
// 	}
// };

// template <typename T>
// void	testAdaptors(T intContainer1, int size){
// 	Unprotect<T> intContainer = &intContainer1;
// 	populate(&intContainer, size);
// 	try {
// 		int intToFind = rand() % 200;
// 		std::cout << std::endl << "The int container is :" << std::endl << std::endl;
// 		printContainer(intContainer);
// 		std::cout << std::endl << std::endl;

// 		std::cout << "The number to find is ";
// 		std::cout << intToFind;
// 		std::cout << " and it ";
// 		easyfind(intContainer, intToFind);
// 	}
// 	catch (std::exception & exception) {
// 		std::cout << exception.what() << std::endl;
// 	}
// }

