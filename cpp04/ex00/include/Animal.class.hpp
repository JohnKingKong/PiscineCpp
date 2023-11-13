/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 11:50:34 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include <iostream>

class Animal {
	public:

		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		virtual ~Animal();

		Animal& operator=(Animal const & rhs);

		std::string		getType() const;

		virtual void		makeSound();

	private:
		void			_setType(std::string type);

	protected:
		std::string type;

};
