/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:56:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/14 17:18:28 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap {
	public:

		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& other);
		virtual ~ClapTrap();

		ClapTrap& operator=(ClapTrap const & rhs);

		

		virtual void	attack(const std::string& target);

		std::string		getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	protected :

		unsigned int		hitPoints;
		unsigned int		energyPoints;
		unsigned int		attackDamage;
		std::string			name;

		void			setName(std::string name);
		void			setAttackDamage(unsigned int dmg);
		void			setHitPoints(unsigned int hp);
		void			setEnergyPoints(unsigned int ep);
};
