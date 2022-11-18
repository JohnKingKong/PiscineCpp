/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:01:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/15 18:34:51 by jvigneau         ###   ########.fr       */
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

		void		setIdea(int ideaPosition, std::string idea);
		std::string	getIdea(int ideaPosition) const;

		void		populateIdeas();

	private:

};
