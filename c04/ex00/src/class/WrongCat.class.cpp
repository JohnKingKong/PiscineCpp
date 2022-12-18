/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 11:57:46 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.class.hpp"


WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat Constructor witn no params called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
	_setType(other.getType());
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const & rhs){
	_setType(rhs.getType());
	return *this;
}

void	WrongCat::makeSound(){
	std::cout << "try to make a sound my fake cat" << std::endl;
}


void	WrongCat::_setType(std::string type) {
	this->type = type;
}


