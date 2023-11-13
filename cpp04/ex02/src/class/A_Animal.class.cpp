/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 12:14:52 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.class.hpp"


A_Animal::A_Animal(){
	std::cout << "A_Animal constructor called(no params)" << std::endl;
}

A_Animal::A_Animal(std::string type) {
	_setType(type);
	std::cout << "A_Animal constructor called (with type as param)" << std::endl;
}

A_Animal::A_Animal(const A_Animal& other){
	_setType(other.getType());
	std::cout << "A_Animal copy constructor called" << std::endl;
}

A_Animal::~A_Animal(){
	std::cout << "A_Animal destructor called" << std::endl;
}



A_Animal& A_Animal::operator=(A_Animal const & rhs){
	_setType(rhs.getType());
	return *this;
}

std::string		A_Animal::getType() const {
	return (this->type);
}

void		A_Animal::_setType(std::string type) {
	this->type = type;
}
