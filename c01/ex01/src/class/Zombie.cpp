/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:38:04 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/01 15:54:10 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Zombie.hpp"

Zombie::Zombie() { set_name(name); }
Zombie::~Zombie() {}


std::string		Zombie::get_name() {
	return (this->name);
}

void		Zombie::set_name(std::string Name) {
	this->name = Name;
}

void		Zombie::announce() { 
	std::cout << purple << get_name() << ": BraiiiiiiiinnnnnnnzzzzZ..." << reset <<std::endl; 
}
