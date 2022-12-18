/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:05:02 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/13 12:11:51 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"


FragTrap::FragTrap() : ClapTrap() {
	setName("Undefined");
	hitPoints = HITPOINTS;
	energyPoints = ENERGYPOINTS;
	attackDamage = ATTACKDAMAGE;
	std::cout << "FragTrap constructor(no params) called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name){
	hitPoints = HITPOINTS;
	energyPoints = ENERGYPOINTS;
	attackDamage = ATTACKDAMAGE;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other.name) {
	*this = other;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const & rhs){
	FragTrap::setName(rhs.getName());
	FragTrap::setAttackDamage(rhs.getAttackDamage());
	FragTrap::setHitPoints(rhs.getHitPoints());
	FragTrap::setEnergyPoints(rhs.getEnergyPoints());
	return *this;
}


void	FragTrap::highFivesGuys() {
	std::cout << "AYOOOOO don't let ma boi " << FragTrap::getName();
	std::cout << " hanging... High five him RIGHT NOW!!!" << std::endl;
}