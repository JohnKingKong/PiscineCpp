/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:56:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/14 13:35:25 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"


ClapTrap::ClapTrap(std::string name){
	setName(name);
	setAttackDamage(0);
	setHitPoints(10);
	setEnergyPoints(10);
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap() {
	setName("");
	setAttackDamage(0);
	setHitPoints(10);
	setEnergyPoints(10);
};

ClapTrap::ClapTrap(const ClapTrap& other){
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){ std::cout << "ClapTrap destructor called" << std::endl; }

ClapTrap& ClapTrap::operator=(ClapTrap const & rhs) {
	ClapTrap::setHitPoints(rhs.getHitPoints());
	ClapTrap::setEnergyPoints(rhs.getEnergyPoints());
	ClapTrap::setName(rhs.getName());
	ClapTrap::setAttackDamage(rhs.getAttackDamage());
	return (*this);
}


std::string		ClapTrap::getName() const {
	return (this->name);
}


unsigned int	ClapTrap::getHitPoints() const {
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const {
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const {
	return (this->attackDamage);
}


void			ClapTrap::setName(std::string name) {
	this->name = name;
}

void			ClapTrap::setHitPoints(unsigned int hp) {
	this->hitPoints = hp;
}

void			ClapTrap::setEnergyPoints(unsigned int ep) {
	this->energyPoints = ep;
}

void			ClapTrap::setAttackDamage(unsigned int dmg) {
	this->attackDamage = dmg;
}


void			ClapTrap::attack(const std::string& target) {
	if ((int)ClapTrap::getEnergyPoints() <= 0)
		std::cout << ClapTrap::getName() << " does not have enough energy points" << std::endl;
	else if ((int)ClapTrap::getHitPoints() <= 0)
		std::cout << ClapTrap::getName() << " does not have any hit points left.... ITS A DEAD PARROT" << std::endl;
	else {
		ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
		std::cout << ClapTrap::getName() << " attacks " << target;
		std::cout << ", causing " << ClapTrap::getAttackDamage();
		std::cout << " points of damage" << std::endl;
	}
}

void			ClapTrap::takeDamage(unsigned int amount) {
	ClapTrap::setHitPoints(ClapTrap::getHitPoints() - amount);
	if ((int)ClapTrap::getHitPoints() < 0)
		ClapTrap::setHitPoints(0);
	std::cout << ClapTrap::getName() << " has taken ";
	std::cout << amount << " points of damage";
	std::cout << std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount) {
	if ((int)ClapTrap::getEnergyPoints() <= 0)
		std::cout << ClapTrap::getName() << " does not have enough energy points" << std::endl;
	else if ((int)ClapTrap::getHitPoints() <= 0)
		std::cout << ClapTrap::getName() << " does not have any hit points left.... ITS A DEAD PARROT" << std::endl;
	else {
		ClapTrap::setHitPoints(ClapTrap::getHitPoints() + amount);
		std::cout << ClapTrap::getName() << " has repaired himself for ";
		std::cout << amount << " hit points" << std::endl;
	}
}