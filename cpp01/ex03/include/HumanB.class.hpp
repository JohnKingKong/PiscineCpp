/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:44:20 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/07 12:50:46 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.class.hpp"

class HumanB {
	public:

		HumanB(std::string name);
		~HumanB();

		void				attack();
		void				setName(std::string name);
		void				setWeapon(Weapon& weapon);
		std::string const 	getName();
		Weapon				getWeapon();

	private:

		std::string		name;
		Weapon*			weapon;

};