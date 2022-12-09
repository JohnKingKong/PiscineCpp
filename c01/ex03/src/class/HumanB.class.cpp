/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:44:20 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/09 15:19:31 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/HumanB.class.hpp"

HumanB::HumanB(std::string name){
	std::cout << "Human B Constructor called" << std::endl;
	HumanB::setName(name);
}

HumanB::~HumanB(){
	std::cout << "Human B Destructor called" << std::endl;
}

void		HumanB::setName(std::string name){
	this->name = name;
}

void		HumanB::attack(){
	std::cout << HumanB::getName() << " attacks with their " << HumanB::getWeapon().Weapon::getType() << std::endl;
}

void		HumanB::setWeapon(Weapon& weapon){
	this->weapon = &weapon;
}

Weapon		HumanB::getWeapon(){
	return *this->weapon;
}
std::string const	HumanB::getName(){
	return this->name;
}