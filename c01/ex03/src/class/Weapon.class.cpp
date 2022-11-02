/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:57:35 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/02 14:34:15 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Weapon.class.hpp"

Weapon::Weapon(std::string type) {
	setType(type);
}
Weapon::~Weapon() {}

void	Weapon::setType(std::string type) {
	this->type = type;
}

std::string const & Weapon::getType() {
	return (this->type);
}


