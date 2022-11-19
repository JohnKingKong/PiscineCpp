/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:29 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/19 16:44:42 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.class.hpp"


PresidentialPardonForm::PresidentialPardonForm() :
			AForm("PresidentialPardonForm", 25, 5) {
	_target = "UNDEFINED";
	std::cout << purple << "PresidentialPardonForm constructor called" << reset << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
			AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << purple << "PresidentialPardonForm constructor called" << reset << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
			AForm("PresidentialPardonForm", 25, 5) {
	std::cout << purple << "PresidentialPardonForm copy constructor called" << reset << std::endl;
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	std::cout << executor << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}


