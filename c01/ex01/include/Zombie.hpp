/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:38:12 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/01 15:35:18 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "./Colors.hpp"

class	Zombie {
	public:
		Zombie();
		~Zombie();

		void			announce();
		void			set_name(std::string Name);
		std::string		get_name();


	private:
		std::string		name;

};