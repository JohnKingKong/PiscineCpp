/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:18 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/14 17:24:16 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"
#include "FragTrap.class.hpp"
#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"

int main()
{
	DiamondTrap	Mario("Mario");



	Mario.beRepaired(3);



	Mario.attack("lol");

	Mario.guardGate();

	Mario.whoAmI();
	return 0;
}
