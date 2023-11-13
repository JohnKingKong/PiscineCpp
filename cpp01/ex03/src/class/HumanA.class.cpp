/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:42:57 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/09 15:19:16 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/HumanA.class.hpp"


HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon){
	std::cout << "Human A Constructor called" << std::endl;
	HumanA::setName(name);
}

HumanA::~HumanA() {
	std::cout << "Human A Destructor called" << std::endl;
}

void	HumanA::attack() {
	std::cout << HumanA::getName() << " attacks with their " << HumanA::getWeapon().Weapon::getType() << std::endl;
}

void	HumanA::setName(std::string name){
	this->name = name;
}

void	HumanA::setWeapon(Weapon& weapon){
	this->weapon = weapon;
}

std::string const	HumanA::getName(){
	return this->name;
}

Weapon&		HumanA::getWeapon(){
	return this->weapon;
}