/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:26:00 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/08 16:17:04 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl {
	public:

		Harl();
		Harl(const Harl&);
		~Harl();

		Harl& operator=(const Harl& e);

		int			op;

		void		debug();
		void		info();
		void		warning();
		void		error();
		void		complain(std::string level);
		int			getLevel(std::string level);
		int			getValue() const;

		void		(Harl::*functionPointer[4])(void);

	private:

};
