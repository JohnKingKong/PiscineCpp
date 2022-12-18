/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 12:17:25 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "A_Animal.class.hpp"

class Cat : public A_Animal {
	public:

		Cat();
		Cat(std::string type);
		Cat(const Cat& other);
		virtual ~Cat();

		Cat& operator=(Cat const & rhs);

		virtual void		makeSound();

	private:
		Brain*		_brain;
		void		_setType(std::string type);
};
