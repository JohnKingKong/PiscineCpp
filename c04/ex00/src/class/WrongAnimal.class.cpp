/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/15 17:37:17 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.class.hpp"


WrongAnimal::WrongAnimal(){}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	*this = other;
}

WrongAnimal::~WrongAnimal(){}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & rhs){
	WrongAnimal::setType(rhs.getType());
	return *this;
}

void		WrongAnimal::makeSound() {
	std::cout << "This is the default sound of the wronganimal" << std::endl;
}

void		WrongAnimal::setType(std::string type) {
	this->type = type;
}

std::string	WrongAnimal::getType() const {
	return (this->type);
}