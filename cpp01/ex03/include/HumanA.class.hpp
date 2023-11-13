/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:42:57 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/07 12:45:36 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.class.hpp"

class HumanA {
	public:

		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void				attack();
		void				setName(std::string name);
		void				setWeapon(Weapon& weapon);
		std::string const 	getName();
		Weapon&				getWeapon();


	private:

		std::string		name;
		Weapon&			weapon;
};