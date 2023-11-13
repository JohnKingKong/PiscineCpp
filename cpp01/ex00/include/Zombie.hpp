/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:38:12 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/01 13:54:59 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "./Colors.hpp"

class	Zombie {
	public:
		Zombie(std::string Name);
		~Zombie();

		void			announce();
		void			set_name(std::string Name);


	private:
		std::string		name;

		std::string		get_name();
};