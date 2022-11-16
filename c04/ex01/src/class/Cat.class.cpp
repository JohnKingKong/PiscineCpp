/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:13:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/15 18:26:18 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"


Cat::Cat() : A_Animal() {
	setType("Cat");
	brain = new Brain();
	std::cout << "Cat constructor called(with no params)" << std::endl;
}

Cat::Cat(std::string type) : A_Animal(type) {
	setType(type);
	std::cout << "Cat constructor called (with no params)" << std::endl;
}

Cat::Cat(const Cat& other) : A_Animal() {
	*this = other;
}

Cat::~Cat(){
	delete(brain);
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const & rhs){
	Cat::setType(rhs.getType());
	return *this;
}

void	Cat::makeSound() {
	std::cout << "MIAOU MEOW MOUUU" << std::endl;
}


