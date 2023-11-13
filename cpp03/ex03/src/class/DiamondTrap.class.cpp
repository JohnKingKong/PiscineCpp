/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:18 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/13 12:12:59 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"
#include "ClapTrap.class.hpp"


DiamondTrap::DiamondTrap() : ClapTrap() {
	setName("Undefined");
	setHitPoints(FragTrap::HITPOINTS);
	setEnergyPoints(ScavTrap::ENERGYPOINTS);
	setAttackDamage(FragTrap::ATTACKDAMAGE);

	std::cout << "DiamondTrap constructor(no params) called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other.name + "_clap_name") {
	*this = other;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	this->name = name;
	setHitPoints(FragTrap::HITPOINTS);
	setEnergyPoints(ScavTrap::ENERGYPOINTS);
	setAttackDamage(FragTrap::ATTACKDAMAGE);

	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & rhs){
	setName(rhs.getName());
	setHitPoints(rhs.getHitPoints());
	setEnergyPoints(rhs.getEnergyPoints());
	setAttackDamage(rhs.getAttackDamage());
	return *this;
}

void	DiamondTrap::whoAmI() {
	std::cout << "My fucking name is " << ClapTrap::name << " or you can call me ";
	std::cout << DiamondTrap::name << std::endl;
}
