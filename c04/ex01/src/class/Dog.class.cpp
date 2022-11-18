/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:13:46 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/16 12:50:20 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"


Dog::Dog() : Animal() {
	setType("Dog");
	brain = new Brain();
	std::cout << "Dog constructor called (witn no param)" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	setType(type);
	std::cout << "Dog constructor called (with type as param)" << std::endl;
}

Dog::Dog(const Dog& other)  : Animal() {
	*this = other;
}

Dog::~Dog(){
	delete(brain);
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const & rhs){
	Dog::setType(rhs.getType());
	return *this;
}

void		Dog::makeSound() {
	std::cout << "WOOOOOOOF WOOOOOF ESTI" << std::endl;
}


