/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 11:54:36 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.class.hpp"


Animal::Animal(){
	std::cout << "Animal constructor called(no params)" << std::endl;
}

Animal::Animal(std::string type) {
	_setType(type);
	std::cout << "Animal constructor called (with type as param)" << std::endl;
}

Animal::Animal(const Animal& other){
	_setType(other.getType());
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}



Animal& Animal::operator=(Animal const & rhs){
	_setType(rhs.getType());
	return *this;
}



void			Animal::_setType(std::string type) {
	this->type = type;
}

std::string		Animal::getType() const {
	return (this->type);
}

void			Animal::makeSound() {
	std::cout << "DEFAULT SOUND INCOMING" << std::endl;
}