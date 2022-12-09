/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:18 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/09 17:19:54 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"
#include "ClapTrap.class.hpp"


DiamondTrap::DiamondTrap() : ClapTrap() {
	setName("Undefined");
	setHitPoints(FragTrap::HITPOINTS);
	setEnergyPoints(ScavTrap::ENERGYPOINTS);
	setAttackDamage(FragTrap::ATTACKDAMAGE);

	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other){
	*this = other;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), name(name) {
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
	std::cout << "My fucking name is " << ClapTrap::getName() << " or you can call me ";
	std::cout << DiamondTrap::getName() << std::endl;
}
