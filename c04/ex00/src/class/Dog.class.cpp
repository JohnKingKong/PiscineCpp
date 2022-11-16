/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:13:46 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/15 17:27:35 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"


Dog::Dog() : A_Animal() {
	setType("Dog");
	std::cout << "Dog constructor called (witn no param)" << std::endl;
}

Dog::Dog(std::string type) : A_Animal(type) {
	setType(type);
	std::cout << "Dog constructor called (with type as param)" << std::endl;
}

Dog::Dog(const Dog& other)  : A_Animal() {
	*this = other;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const & rhs){
	Dog::setType(rhs.getType());
	return *this;
}

void		Dog::makeSound() {
	std::cout << "WOOOOOOOF WOOOOOF ESTI" << std::endl;
}


