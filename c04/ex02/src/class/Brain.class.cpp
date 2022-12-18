/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:01:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 12:15:39 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"


Brain::Brain(){
	std::cout << "the brain has been started" << std::endl;
	_populateIdeas();
	std::cout << "the ideas number 2 is : " << getIdea(2);
	std::cout << " and the number 98 is : " << getIdea(98) << std::endl;
}

Brain::Brain(const Brain& other){
	for (int i = 0; i < 100; i++)
		_setIdea(i, other.getIdea(i));
	std::cout << "brain copy constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "the brain has been destroyed" << std::endl;
}

Brain& Brain::operator=(Brain const & rhs){
	for (int i = 0; i < 100; i++)
		_setIdea(i, rhs.getIdea(i));
	return *this;
}

std::string	Brain::getIdea(int ideaPosition) const {
	return (this->ideas[ideaPosition]);
}

void		Brain::_setIdea(int ideaPosition, std::string idea) {
	this->ideas[ideaPosition] = idea;
}

void		Brain::_populateIdeas() {
	for (int i = 0; i < 100; i++)
		_setIdea(i, "DEFAULT");
}

