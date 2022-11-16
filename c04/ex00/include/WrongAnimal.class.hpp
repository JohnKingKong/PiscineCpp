/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/15 17:37:34 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal {
	public:

		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal();

		WrongAnimal& operator=(WrongAnimal const & rhs);

		void			setType(std::string type);
		std::string		getType() const;

		void	makeSound();

	private:
		std::string		type;

};
