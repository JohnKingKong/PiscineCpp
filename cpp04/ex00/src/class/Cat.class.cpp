/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:13:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 11:54:57 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"


Cat::Cat() : Animal("Cat") {
	_setType("Cat");
	std::cout << "Cat constructor called(with no params)" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	_setType(type);
	std::cout << "Cat constructor called (with no params)" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other.getType()) {
	_setType(other.getType());
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const & rhs){
	_setType(rhs.getType());
	return *this;
}

void	Cat::_setType(std::string type) {
	this->type = type;
}

void	Cat::makeSound() {
	std::cout << "MIAOU MEOW MOUUU" << std::endl;
}


