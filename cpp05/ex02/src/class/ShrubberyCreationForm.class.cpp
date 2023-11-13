/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:29 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/21 14:50:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.class.hpp"

/*---------Constructors and Destructors---------*/


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



/*--------------Operators overload--------------*/


ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}



/*-------------NonMember static functions--------------*/


static void	createTrees(std::string targetName) {
	std::fstream	tempStream;
	const char *	name;
	name = targetName.c_str();
	tempStream.open(name, std::ios::out);
	tempStream << "              /\\ " << std::endl;
	tempStream << "             <  >" << std::endl;
	tempStream << "              \\/ " << std::endl;
	tempStream << "              /\\ " << std::endl;
	tempStream << "             /  \\ " << std::endl;
	tempStream << "            /++++\\ " << std::endl;
	tempStream << "           /  ()  \\ " << std::endl;
	tempStream << "           /      \\ " << std::endl;
	tempStream << "          /~`~`~`~`\\ " << std::endl;
	tempStream << "         /  ()  ()  \\ " << std::endl;
	tempStream << "         /          \\ " << std::endl;
	tempStream << "        /*&*&*&*&*&*&\\ " << std::endl;
	tempStream << "       /  ()  ()  ()  \\ " << std::endl;
	tempStream << "       /              \\ " << std::endl;
	tempStream << "      /++++++++++++++++\\ " << std::endl;
	tempStream << "     /  ()  ()  ()  ()  \\ " << std::endl;
	tempStream << "     /                  \\ " << std::endl;
	tempStream << "    /~`~`~`~`~`~`~`~`~`~`\\ " << std::endl;
	tempStream << "   /  ()  ()  ()  ()  ()  \\ " << std::endl;
	tempStream << "   /*&*&*&*&*&*&*&*&*&*&*&\\ " << std::endl;
	tempStream << "  /                        \\ " << std::endl;
	tempStream << " /,.,.,.,.,.,.,.,.,.,.,.,.,.\\ " << std::endl;
	tempStream << "            |   |             " << std::endl;
	tempStream << "           |`````|            " << std::endl;
	tempStream << "           \\_____/            " << std::endl;
	tempStream.close();
}


/*-----------Public member functions------------*/


void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getSignedStatus() == false)
		throw(AForm::FormNotSignedException());
	if (executor.getGrade() > this->getGradeToUse()) {
		std::cout << red << executor.getName() << " couldn't execute the " << this->getName() << " because : ";
		throw(AForm::GradeTooHighException());
	}
	else
		createTrees(this->_target + "_shrubbery");
}



