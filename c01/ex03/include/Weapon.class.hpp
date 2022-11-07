/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:58:53 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/07 12:31:32 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	
#pragma once

# include <iostream>

class Weapon {

	public:

		Weapon(std::string type);
		~Weapon();

		std::string const &		getType();
		void					setType(std::string type);

	private:

		std::string		type;

};