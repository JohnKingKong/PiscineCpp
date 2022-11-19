/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:29 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/19 16:44:40 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.class.hpp"
#include "AForm.class.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() :
			AForm("ShrubberyCreationForm", 145, 137) {
	_target = "UNDEFINED";
	std::cout << purple << "ShrubberyCreationForm constructor called" << reset << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
			AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << purple << "ShrubberyCreationForm constructor called" << reset << std::endl;
		}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
			AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << purple << "ShrubberyCreationForm copy constructor called" << reset << std::endl;
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::cout << executor << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}


