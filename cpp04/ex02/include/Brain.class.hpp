/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:01:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 12:15:17 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain {
	public:

		Brain();
		Brain(const Brain& other);
		~Brain();

		Brain& operator=(Brain const & rhs);

		std::string		ideas[100];

		std::string	getIdea(int ideaPosition) const;


	private:
		void		_setIdea(int ideaPosition, std::string idea);
		void		_populateIdeas();

};
