/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 11:56:52 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.class.hpp"


WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal Constructor witn no params called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	_setType(other.getType());
	std::cout << "WrongAnimal copy constructyor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & rhs){
	_setType(rhs.getType());
	return *this;
}

void		WrongAnimal::makeSound() {
	std::cout << "This is the default sound of the wronganimal" << std::endl;
}

void		WrongAnimal::_setType(std::string type) {
	this->type = type;
}

std::string	WrongAnimal::getType() const {
	return (this->type);
}