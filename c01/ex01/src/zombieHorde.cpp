/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:24:18 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/01 15:52:43 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*		zombieHorde(int N, std::string Name) {

	if (N <= 0) return NULL;

	Zombie*		Zombies = new Zombie[N];
	for (int i = 0;i < N; i++)
		Zombies[i].set_name(Name);
	return Zombies;
}