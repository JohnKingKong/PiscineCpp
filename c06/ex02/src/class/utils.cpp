/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:30:05 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/25 15:46:15 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Base	*generate() {
	int	randomNumber;
	Base *test;

	srand(time(NULL));
	randomNumber = rand()% 99;
	if (randomNumber <= 33)
		test = new A;
	else if (randomNumber <= 66)
		test = new B;
	else
		test = new C;
	return test;
}

void	identify(Base *ptr) {
	A	*a= dynamic_cast<A *>(ptr);
	if (a) {
		std::cout << "the type is A" << std::endl;
		return ;
	}
	B	*b = dynamic_cast<B *>(ptr);
	if (b) {
		std::cout << "the type is B" << std::endl;
		return ;
	}
	C	*c = dynamic_cast<C *>(ptr);
	if (c) {
		std::cout << "the type is C" << std::endl;
		return ;
	}
}

void	identify(Base& ptr) {
	try {
		A &a = dynamic_cast<A &>(ptr);
		(void)a;
		std::cout << "type is A" << std::endl;
		return;
	}
	catch(const std::exception& e){}
	try {
		B &b = dynamic_cast<B &>(ptr);
		(void)b;
		std::cout  << "type is B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try {
		C &c = dynamic_cast<C &>(ptr);
		(void)c;
		std::cout << "type is c" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	std::cout << "type is Base" << std::endl;
}