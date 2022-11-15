/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:32:18 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/14 16:47:00 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ScavTrap.class.hpp"
#include "FragTrap.class.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	public:

		DiamondTrap();
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap(const std::string& name);
		virtual ~DiamondTrap();

		DiamondTrap& operator=(DiamondTrap const & rhs);

		void		whoAmI();

		// virtual void		attack(const std::string& target);

	private:
		std::string	name;
};
