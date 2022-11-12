/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:56:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/12 18:05:26 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"


ClapTrap::ClapTrap(std::string name){
	_setName(name);
	_setAttackDamage(0);
	_setHitPoints(10);
	_setEnergyPoints(10);
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){ std::cout << "Destructor called" << std::endl; }

// ClapTrap& ClapTrap::operator=(ClapTrap const & rhs){
// 	ClapTrap::<CHANGE_FUNC_NAME>(e.<CHANGE_FUNC_NAME>());
// 	return *this;
// }


std::string		ClapTrap::getName() {
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints() {
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() {
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() {
	return (this->attackDamage);
}


void			ClapTrap::_setName(std::string name) {
	this->name = name;
}

void			ClapTrap::_setHitPoints(unsigned int hp) {
	this->hitPoints = hp;
}

void			ClapTrap::_setEnergyPoints(unsigned int ep) {
	this->energyPoints = ep;
}

void			ClapTrap::_setAttackDamage(unsigned int dmg) {
	this->attackDamage = dmg;
}


void			ClapTrap::attack(const std::string& target) {
	if (ClapTrap::getEnergyPoints() == 0)
		std::cout << ClapTrap::getName() << " does not have enough energy points" << std::endl;
	else if (ClapTrap::getHitPoints() == 0)
		std::cout << ClapTrap::getName() << " does not have any hit points left.... ITS A DEAD PARROT" << std::endl;
	else {
		ClapTrap::_setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
		std::cout << ClapTrap::getName() << " attacks " << target;
		std::cout << ", causing " << ClapTrap::getAttackDamage();
		std::cout << " points of damage" << std::endl;
	}
}

void			ClapTrap::takeDamage(unsigned int amount) {
	ClapTrap::_setHitPoints(ClapTrap::getHitPoints() - amount);
	std::cout << ClapTrap::getName() << " has taken ";
	std::cout << amount << " points of damage";
	std::cout << std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount) {
	if (ClapTrap::getEnergyPoints() == 0)
		std::cout << ClapTrap::getName() << " does not have enough energy points" << std::endl;
	else if (ClapTrap::getHitPoints() == 0)
		std::cout << ClapTrap::getName() << " does not have any hit points left.... ITS A DEAD PARROT" << std::endl;
	else {
		ClapTrap::_setHitPoints(ClapTrap::getHitPoints() + amount);
		std::cout << ClapTrap::getName() << " has repaired himself for ";
		std::cout << amount << " hit points" << std::endl;
	}
}