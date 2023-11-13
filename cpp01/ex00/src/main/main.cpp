/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:29:20 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/01 13:58:50 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*		newZombie(std::string Name);
void		randomChump(std::string Name);

int main() {
	Zombie	*zombiePTR;

	zombiePTR = newZombie("Michael Reeves");
	(*zombiePTR).announce();
	randomChump("Robodog");
	std::cout << red << "Get REKT Michael Reeves" << reset << std::endl;
	delete zombiePTR;
}