/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:42:57 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/02 15:03:36 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.class.hpp"

class HumanA {
	public:

		HumanA(std::string name, Weapon& type);
		~HumanA();

		void			attack();
		std::string		getName();
		Weapon			getWeapon();
		void			setWeapon(Weapon type);


	private:

		std::string		name;
		Weapon&			weapon;
};