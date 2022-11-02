/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:44:20 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/02 14:53:09 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.class.hpp"

class HumanB {
	public:

		HumanB();
		~HumanB();

	private:

		std::string		name;
		Weapon			weapon;
};