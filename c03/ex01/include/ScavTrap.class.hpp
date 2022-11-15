/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:46:12 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/14 13:41:11 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.class.hpp"

class ScavTrap : public ClapTrap{
	public:

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		virtual ~ScavTrap();

		ScavTrap& operator=(ScavTrap const & rhs);

		virtual void	attack(const std::string& target);

		void			guardGate();

	private:

};
