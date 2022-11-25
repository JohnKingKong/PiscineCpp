/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:39:55 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/25 14:56:20 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main()
{
	ClapTrap	Bob("Bob");
	ClapTrap	Paul("Paul");



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

	return 0;
}