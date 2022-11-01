/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:29:20 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/01 15:59:57 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*		zombieHorde(int N, std::string Name);

int main() {
	Zombie*	zombies = zombieHorde(5, "Michael Reeves");

	for (int i = 0; i < 5; i++)
		zombies[i].announce();

	delete [] zombies;
}