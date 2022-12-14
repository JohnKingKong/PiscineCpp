/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 12:13:53 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.class.hpp"

class A_Animal {
	public:

		A_Animal();
		A_Animal(std::string type);
		A_Animal(const A_Animal& other);
		virtual ~A_Animal();

		A_Animal& operator=(A_Animal const & rhs);

		std::string			getType() const;

		virtual void		makeSound() = 0;

	private:
		void				_setType(std::string type);

	protected:
		std::string type;

};
