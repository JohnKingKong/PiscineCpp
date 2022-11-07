/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:44:20 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/07 12:57:52 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/HumanB.class.hpp"

HumanB::HumanB(std::string name){
	HumanB::setName(name);
}

HumanB::~HumanB(){

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