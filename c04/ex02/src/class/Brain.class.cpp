/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:01:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/15 18:37:19 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"


Brain::Brain(){}

Brain::Brain(const Brain& other){
	*this = other;
}

Brain::~Brain(){}

Brain& Brain::operator=(Brain const & rhs){
	for (int i = 0; i < 100; i++)
		Brain::setIdea(i, rhs.getIdea(i));
	return *this;
}

void		Brain::setIdea(int ideaPosition, std::string idea) {
	this->ideas[ideaPosition] = idea;
}

std::string	Brain::getIdea(int ideaPosition) const {
	return (this->ideas[ideaPosition]);
}

void		Brain::populateIdeas() {
	for (int i = 0; i < 100; i++)
		ideas[i] = "DEFAULT";
}


