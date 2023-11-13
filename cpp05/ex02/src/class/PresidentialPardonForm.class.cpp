/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:29 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/21 14:46:26 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.class.hpp"


/*---------Constructors and Destructors---------*/


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



/*--------------Operators overload--------------*/


PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}



/*-----------Public member functions------------*/


void		PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getSignedStatus() == false)
		throw(AForm::FormNotSignedException());
	if (executor.getGrade() > this->getGradeToUse()) {
		std::cout << red << executor.getName() << " couldn't execute the " << this->getName() << " because : ";
		throw(AForm::GradeTooHighException());
	}
	else
		std::cout << this->_target << " has been pardonned by the great Zaphod Beeblerox" << std::endl;
}

