/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:29 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/19 16:47:14 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.class.hpp"


RobotomyRequestForm::RobotomyRequestForm() : 
			AForm("RobotomyRequestForm", 72, 45) {
	std::cout << purple << "RobotomyRequestForm constructor called" << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
			AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << purple << "RobotomyRequestForm constructor called" << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
			AForm("RobotomyRequestForm", 72, 45) {
	std::cout << purple << "RobotomyRequestForm copy constructor called" << reset << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void			RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	std::cout << executor << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}


