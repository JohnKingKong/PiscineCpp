/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 11:50:54 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.class.hpp"

class Dog : public Animal {
	public:

		Dog();
		Dog(std::string type);
		Dog(const Dog& other);
		virtual ~Dog();

		Dog& operator=(Dog const & rhs);

		virtual void		makeSound();

	private:
		void			_setType(std::string type);

};
