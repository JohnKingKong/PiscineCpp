/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:05:02 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/14 17:18:41 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.class.hpp"

class FragTrap : virtual public ClapTrap {
	public :

		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap& other);
		virtual ~FragTrap();

		FragTrap& operator=(FragTrap const & rhs);

		void	highFivesGuys();

	protected :
		static const unsigned int	HITPOINTS = 100;
		static const unsigned int	ENERGYPOINTS = 100;
		static const unsigned int	ATTACKDAMAGE = 30;

};
