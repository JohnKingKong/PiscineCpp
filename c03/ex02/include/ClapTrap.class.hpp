/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:56:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/14 13:41:26 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap {
	public:

		ClapTrap(std::string name);
		ClapTrap();
		ClapTrap(const ClapTrap& other);
		virtual ~ClapTrap();

		ClapTrap& operator=(ClapTrap const & rhs);

		unsigned int		hitPoints;
		unsigned int		energyPoints;
		unsigned int		attackDamage;
		std::string			name;

		virtual void	attack(const std::string& target);

		std::string		getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;
		void			setAttackDamage(unsigned int dmg);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			setEnergyPoints(unsigned int ep);

	protected :

		void			setName(std::string name);
		void			setHitPoints(unsigned int hp);

};
