/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/15 17:31:49 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.class.hpp"


A_Animal::A_Animal(){
	std::cout << "A_Animal constructor called(no params)" << std::endl;
}

A_Animal::A_Animal(std::string type) {
	setType(type);
	std::cout << "A_Animal constructor called (with type as param)" << std::endl;
}

A_Animal::A_Animal(const A_Animal& other){
	*this = other;
}

A_Animal::~A_Animal(){
	std::cout << "A_Animal destructor called" << std::endl;
}



A_Animal& A_Animal::operator=(A_Animal const & rhs){
	A_Animal::setType(rhs.getType());
	return *this;
}



void			A_Animal::setType(std::string type) {
	this->type = type;
}

std::string		A_Animal::getType() const {
	return (this->type);
}

void			A_Animal::makeSound() {
	std::cout << "DEFAULT SOUND INCOMING" << std::endl;
}