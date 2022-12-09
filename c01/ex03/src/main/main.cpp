/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:35:49 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/09 16:25:14 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Weapon.class.hpp"
#include "../../include/HumanA.class.hpp"
#include "../../include/HumanB.class.hpp"

int main()
{
	
	Weapon club = Weapon("FUCKING HUGE CLUB");
	HumanA	bob("bob", club);

	bob.attack();
	club.setType("really tiny tiny ity bitty club");
	bob.attack();

	Weapon club2 = Weapon("balls of steel");
	HumanB	jim("jim");
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("fire bad boy i got fire");
	jim.attack();
	return 0;
}