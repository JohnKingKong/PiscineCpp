/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:41 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 11:51:02 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.class.hpp"

class WrongCat : public WrongAnimal {
	public:

		WrongCat();
		WrongCat(const WrongCat& other);
		virtual ~WrongCat();

		WrongCat& operator=(WrongCat const & rhs);

		virtual void	makeSound();


	private:
		void			_setType(std::string type);

};
