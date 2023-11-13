/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:05:02 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/14 14:32:46 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.class.hpp"

class FragTrap : public ClapTrap {
	public :

		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		virtual ~FragTrap();

		FragTrap& operator=(FragTrap const & rhs);

		void	highFivesGuys();

	protected :


};
