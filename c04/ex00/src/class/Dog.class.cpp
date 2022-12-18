/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:13:46 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 11:56:00 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"


Dog::Dog() : Animal() {
	_setType("Dog");
	std::cout << "Dog constructor called (witn no param)" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	_setType(type);
	std::cout << "Dog constructor called (with type as param)" << std::endl;
}

Dog::Dog(const Dog& other)  : Animal() {
	_setType(other.getType());
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const & rhs){
	_setType(rhs.getType());
	return *this;
}

void		Dog::_setType(std::string type) {
	this->type = type;
}

void		Dog::makeSound() {
	std::cout << "WOOOOOOOF WOOOOOF ESTI" << std::endl;
}


