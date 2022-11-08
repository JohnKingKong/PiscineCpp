/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:26:00 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/08 18:08:27 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Harl.class.hpp"
#include "../../include/Complaining.hpp"
#include <string>


Harl::Harl(){
	Harl::op = 42;
	Harl::functionPointer[0] = &Harl::debug;
	Harl::levelMessage[0] = "DEBUG";
	Harl::functionPointer[1] = &Harl::info;
	Harl::levelMessage[1] = "INFO";
	Harl::functionPointer[2] = &Harl::warning;
	Harl::levelMessage[2] = "WARNING";
	Harl::functionPointer[3] = &Harl::error;
	Harl::levelMessage[3] = "ERROR";
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

void	Harl::complain(int index){
	(this->*functionPointer[index])();
}

int		Harl::getLevel(std::string level){
	for (int i = 0; i < 4; i++){
		if (level == levelMessage[i])
			return i;
	}
	std::cout << "The complaining encountered a problem" << std::endl;
	return -1;
}

void	Harl::filter(std::string level){
	int index = Harl::getLevel(level);
	if (index >= 0) {
		while (index <= 3) {
			Harl::complain(index);
			index++;
		}
	}
}

