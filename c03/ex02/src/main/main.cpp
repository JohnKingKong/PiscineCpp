/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:05:02 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/14 14:33:20 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"
#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"

int main()
{
	ClapTrap	Bob("Bob");
	FragTrap	Paul("Paul");
	ScavTrap	Mario("Mario");



	Bob.attack(Paul.getName());
	Paul.takeDamage(Bob.getAttackDamage());
	while ((int)Bob.getHitPoints() > 0 && (int)Paul.getEnergyPoints() > 0) {
		Paul.attack(Bob.getName());
		Bob.takeDamage(Paul.getAttackDamage());
	}

	Bob.beRepaired(1);
	Paul.beRepaired(2);
	Mario.beRepaired(3);



	while ((int)Paul.getHitPoints() > 0 && (int) Mario.getEnergyPoints() > 0) {
		Mario.attack(Paul.getName());
		Paul.takeDamage(Mario.getAttackDamage());
	}

	Paul.attack(Mario.getName());

	Mario.setEnergyPoints(0);

	Mario.attack(Bob.getName());

	Mario.guardGate();

	Paul.highFivesGuys();
	return 0;
}
