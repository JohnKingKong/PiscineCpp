/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:57:35 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/09 15:19:47 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Weapon.class.hpp"

Weapon::Weapon(std::string type){
	std::cout << "Weapon Constructor called" << std::endl;
	setType(type);
}

Weapon::~Weapon(){
	std::cout << "Weapon Destructor called" << std::endl;
}

std::string const &		Weapon::getType(){
	return this->type;
}

void		Weapon::setType(std::string type){
	this->type = type;
}