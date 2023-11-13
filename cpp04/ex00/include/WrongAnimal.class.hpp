/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 11:56:13 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal {
	public:

		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(WrongAnimal const & rhs);

		std::string		getType() const;

		virtual void	makeSound();

	private:
		void			_setType(std::string type);

	protected:
		std::string		type;

};
