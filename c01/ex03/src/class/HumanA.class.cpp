/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:42:57 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/07 12:47:38 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/HumanA.class.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon){
	HumanA::setName(name);
}

HumanA::~HumanA() {
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