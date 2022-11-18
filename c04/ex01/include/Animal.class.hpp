/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/16 12:48:11 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.class.hpp"

class Animal {
	public:

		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		virtual ~Animal();

		Animal& operator=(Animal const & rhs);

		void			setType(std::string type);
		std::string		getType() const;

		virtual void		makeSound();

	private:

	protected:
		std::string type;

};
