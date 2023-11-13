/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:56:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/14 11:50:24 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap {
	public:

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		ClapTrap& operator=(ClapTrap const & rhs);
		unsigned int		hitPoints;
		unsigned int		energyPoints;
		unsigned int		attackDamage;
		std::string			name;


		std::string		getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;
		void			_setAttackDamage(unsigned int dmg);
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	private:

		void			_setName(std::string name);
		void			_setHitPoints(unsigned int hp);
		void			_setEnergyPoints(unsigned int ep);

};
