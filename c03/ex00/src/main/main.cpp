/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:56:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/12 18:22:34 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main() {
	
	ClapTrap	Bob("Bob");
	ClapTrap	Paul("Paul");

	Bob._setAttackDamage(1);

	while (Bob.getEnergyPoints() != 1) {
		Bob.attack(Paul.getName());
		Paul.takeDamage(Bob.getAttackDamage());
	}
	while (Paul.getHitPoints() != 10)
		Paul.beRepaired(1);
	return 0;
}