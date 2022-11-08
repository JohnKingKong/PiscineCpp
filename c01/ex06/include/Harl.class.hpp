/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:26:00 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/08 17:54:01 by jvigneau         ###   ########.fr       */
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

		int				op;
		std::string		levelMessage[4];

		void		debug();
		void		info();
		void		warning();
		void		error();
		void		complain(int index);
		int			getLevel(std::string level);
		int			getValue() const;
		void		filter(std::string level);

		void		(Harl::*functionPointer[4])(void);

	private:

};
