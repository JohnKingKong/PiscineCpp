/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:26:00 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/08 17:36:26 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Harl.class.hpp"
#include "../../include/Complaining.hpp"
#include <string>


Harl::Harl(){
	Harl::op = 42;
	Harl::functionPointer[0] = &Harl::debug;
	Harl::functionPointer[1] = &Harl::info;
	Harl::functionPointer[2] = &Harl::warning;
	Harl::functionPointer[3] = &Harl::error;
}

Harl::Harl(const Harl&){}

Harl::~Harl(){}

Harl& Harl::operator=(const Harl& e){
	this->op = e.getValue();
	return *this;
}

int	Harl::getValue() const {
	return this->op;
}

void	Harl::debug() {
	std::cout << DEBUG << std::endl;
}

void	Harl::info(){
	std::cout << INFO << std::endl;
}

void	Harl::warning(){
	std::cout << WARNING << std::endl;
}

void	Harl::error(){
	std::cout << ERROR << std::endl;
}

void	Harl::complain(std::string level){
	int	index = Harl::getLevel(level);
	if (index > 3){ 
		std::cout << "The level of complaining is too damn high" << std::endl;
		return ;
	}
	else if (index < 0){
		std::cout << "Karen look bizzarely happy..." << std::endl;
		return ;
	}
	(this->*functionPointer[index])();
}

int		Harl::getLevel(std::string level){
	return (std::stoi(level));

}

