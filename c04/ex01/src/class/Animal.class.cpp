/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/16 12:49:55 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"


Animal::Animal(){
	std::cout << "Animal constructor called(no params)" << std::endl;
}

Animal::Animal(std::string type) {
	setType(type);
	std::cout << "Animal constructor called (with type as param)" << std::endl;
}

Animal::Animal(const Animal& other){
	*this = other;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}



Animal& Animal::operator=(Animal const & rhs){
	Animal::setType(rhs.getType());
	return *this;
}



void			Animal::setType(std::string type) {
	this->type = type;
}

std::string		Animal::getType() const {
	return (this->type);
}

void			Animal::makeSound() {
	std::cout << "DEFAULT SOUND INCOMING" << std::endl;
}