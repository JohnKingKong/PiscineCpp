/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:46:12 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/13 12:11:27 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"
#include "ClapTrap.class.hpp"


ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name){
	hitPoints = HITPOINTS;
	energyPoints = ENERGYPOINTS;
	attackDamage = ATTACKDAMAGE;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap() {
	setName("Undefined");
	hitPoints = HITPOINTS;
	energyPoints = ENERGYPOINTS;
	attackDamage = ATTACKDAMAGE;
};

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.name) {
	*this = other;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}


ScavTrap& ScavTrap::operator=(ScavTrap const & rhs) {
	ScavTrap::setName(rhs.getName());
	ScavTrap::setHitPoints(rhs.getHitPoints());
	ScavTrap::setEnergyPoints(rhs.getEnergyPoints());
	ScavTrap::setAttackDamage(rhs.getAttackDamage());
	return *this;
}


void	ScavTrap::attack(const std::string& target) {
	if ((int)ScavTrap::getEnergyPoints() <= 0) {
		std::cout << ScavTrap::getName() << " has used all of his precious energy points";
		std::cout << " he has " << ScavTrap::getEnergyPoints() << " left!!!" << std::endl;
	}
	else if ((int)ScavTrap::getHitPoints() <= 0) {
		std::cout << ScavTrap::getName() << " is a dead dead boi... why you playing with";
		std::cout << " a dead boi...." << std::endl;
	}
	else {
		ScavTrap::setEnergyPoints(ScavTrap::getEnergyPoints() - 1);
		std::cout << "Ma boi " << ScavTrap::getName() << " did some crazy stuff";
		std::cout << " and attacked " << target << " for " << ScavTrap::getAttackDamage();
		std::cout << "!!!!!!" << std::endl;
	}
	return ;
}

void	ScavTrap::guardGate() {
	std::cout << "WTF " << ScavTrap::getName() << " has entered a weird state...";
	std::cout << " a GuardGate State.... whatever the f that means...."<< std::endl;
}
