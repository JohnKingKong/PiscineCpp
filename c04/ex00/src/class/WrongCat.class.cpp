/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/15 17:38:22 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.class.hpp"


WrongCat::WrongCat() : WrongAnimal() {}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
	*this = other;
}

WrongCat::~WrongCat() {}

WrongCat& WrongCat::operator=(WrongCat const & rhs){
	WrongCat::setType(rhs.getType());
	return *this;
}

void	makeSound(){
	std::cout << "try to make a sound my fake cat" << std::endl;
}


