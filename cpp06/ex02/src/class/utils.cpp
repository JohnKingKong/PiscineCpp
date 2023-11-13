/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:30:05 by jvigneau          #+#    #+#             */
/*   Updated: 2023/01/11 15:19:00 by jvigneau         ###   ########.fr       */
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
		std::cout << "the type by ptr is A" << std::endl;
		return ;
	}
	B	*b = dynamic_cast<B *>(ptr);
	if (b) {
		std::cout << "the type by ptr is B" << std::endl;
		return ;
	}
	C	*c = dynamic_cast<C *>(ptr);
	if (c) {
		std::cout << "the type by ptr is C" << std::endl;
		return ;
	}
}

void	identify(Base& ptr) {
	try {
		A &a = dynamic_cast<A &>(ptr);
		(void)a;
		std::cout << "type by ref is A" << std::endl;
		return;
	}
	catch(const std::exception& e){}
	try {
		B &b = dynamic_cast<B &>(ptr);
		(void)b;
		std::cout  << "type by ref is B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try {
		C &c = dynamic_cast<C &>(ptr);
		(void)c;
		std::cout << "type by ref is c" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
}