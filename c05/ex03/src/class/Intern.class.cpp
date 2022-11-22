/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:53:45 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/22 14:49:36 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"

Intern::Intern() {
	Intern::functionPointer[0] = &Intern::_makePresidentialPardonForm;
	Intern::functionPointer[1] = &Intern::_makeShrubberyCreationForm;
	Intern::functionPointer[2] = &Intern::_makeRobotomyRequestForm;
}

Intern::Intern(const Intern& other){
	*this = other;
}

Intern::~Intern() {
}

Intern& Intern::operator=(Intern const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

AForm*		Intern::checkForm(std::string formName, std::string target) {
	switch(_checkValidFormName(formName)) {
		case 0:
			return (this->*functionPointer[0])(target);
		case 1:
			return (this->*functionPointer[1])(target);
		case 2:
			return (this->*functionPointer[2])(target);
		default:
			throw(AForm::FormNameInvalidException());
	}
}

AForm*		Intern::makeForm(std::string formName, std::string target) {
	return (checkForm(formName, target));
}

AForm*		Intern::_makeRobotomyRequestForm(std::string target) {
	std::cout << green << "Intern created a RobotomyRequest form." << reset << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm*		Intern::_makeShrubberyCreationForm(std::string target) {
	std::cout << green << "Intern created a ShrubberyCreation form." << reset << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm*		Intern::_makePresidentialPardonForm(std::string target) {
	std::cout << green << "Intern created a PresidentialPardon form." << reset << std::endl;
	return (new PresidentialPardonForm(target));
}

int		Intern::_checkValidFormName(std::string formName) {
	if (formName.find("PresidentialPardon", 0) != formName.npos)
		return 0;
	if (formName.find("ShrubberyCreation", 0) != formName.npos)
		return 1;
	if (formName.find("RobotomyRequest", 0) != formName.npos)
		return 2;
	return -1;

}
