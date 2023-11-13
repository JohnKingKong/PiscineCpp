/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:46:12 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/13 12:19:38 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.class.hpp"

class ScavTrap : virtual public ClapTrap{
	public:

		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		virtual ~ScavTrap();

		ScavTrap& operator=(ScavTrap const & rhs);

		virtual void	attack(const std::string& target);

		void			guardGate();

	protected :
		static const unsigned int HITPOINTS = 100;
		static const unsigned int ENERGYPOINTS = 50;
		static const unsigned int ATTACKDAMAGE = 20;
};
