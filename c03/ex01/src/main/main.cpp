/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:39:55 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/14 13:42:59 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"

int main()
{
	ClapTrap	Bob("Bob");
	ScavTrap	Paul("Paul");
	ScavTrap	Mario("Mario");



	Bob.attack(Paul.getName());
	Paul.takeDamage(Bob.getAttackDamage());
	while ((int)Bob.getHitPoints() > 0 && (int)Paul.getEnergyPoints() > 0) {
		Paul.attack(Bob.getName());
		Bob.takeDamage(Paul.getAttackDamage());
		std::cout << "Bob HP : " << (int)Bob.getHitPoints() << std::endl;
		std::cout << "Paul Mp : " << (int)Paul.getEnergyPoints() << std::endl;
	}

	Bob.beRepaired(1);
	Paul.beRepaired(2);
	std::cout << "Bob HP : " << (int)Bob.getHitPoints() << std::endl;
	std::cout << "Paul Mp : " << (int)Paul.getEnergyPoints() << std::endl;
	std::cout << "Bob Mp : " << (int)Bob.getEnergyPoints() << std::endl;

	Mario.guardGate();
	while ((int)Paul.getHitPoints() > 0 && (int) Mario.getEnergyPoints() > 0) {
		Mario.attack(Paul.getName());
		Paul.takeDamage(Mario.getAttackDamage());
		std::cout << "Paul Hp : " << (int)Paul.getHitPoints() << std::endl;
		std::cout << "Mario Ep : " << (int)Mario.getEnergyPoints() << std::endl;
	}

	Paul.attack(Mario.getName());
	
	Mario.setEnergyPoints(0);

	Mario.attack(Bob.getName());
	return 0;
}