/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 12:17:28 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "A_Animal.class.hpp"

class Dog : public A_Animal {
	public:

		Dog();
		Dog(std::string type);
		Dog(const Dog& other);
		virtual ~Dog();

		Dog& operator=(Dog const & rhs);

		virtual void		makeSound();

	private:
		Brain*		_brain;
		void		_setType(std::string type);
};
