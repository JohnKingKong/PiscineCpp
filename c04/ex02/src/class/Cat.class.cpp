/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:13:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 12:16:35 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"


Cat::Cat() : A_Animal() {
	_setType("Cat");
	_brain = new Brain();
	std::cout << "Cat constructor called(with no params)" << std::endl;
}

Cat::Cat(std::string type) : A_Animal(type) {
	_setType(type);
	std::cout << "Cat constructor called (with no params)" << std::endl;
}

Cat::Cat(const Cat& other) : A_Animal(other) {
	_setType(other.type);
	this->_brain = new Brain(*(other._brain));
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(){
	delete(_brain);
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const & rhs){
	_setType(rhs.getType());
	return *this;
}

void	Cat::makeSound() {
	std::cout << "MIAOU MEOW MOUUU" << std::endl;
}

void	Cat::_setType(std::string type) {
	this->type = type;
}


