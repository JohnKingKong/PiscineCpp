/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:02:20 by jvigneau          #+#    #+#             */
/*   Updated: 2023/01/10 15:25:51 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"



/*---------Constructors and Destructors---------*/


Bureaucrat::Bureaucrat() : _name("DEFAULT") {
	_setGrade(150);
	std::cout << purple << "Default bureaucrat constructor(no params) called" << reset << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	_setGrade(grade);
	_verifyGrade();
	std::cout << purple << "Default bureaucrat constructor(with params) called" << reset << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
	*this = other;
	_verifyGrade();
	std::cout << purple << "Copy bureaucrat constructor called" << reset << std::endl;
}

Bureaucrat::~Bureaucrat(){
}



/*--------------Operators overload--------------*/


Bureaucrat&	Bureaucrat::operator = (Bureaucrat const & rhs){
	Bureaucrat::_setGrade(rhs.getGrade());
	return *this;
}

Bureaucrat&	Bureaucrat::operator ++ () {
	--_grade;
	_verifyGrade();
	return (*this);
}

Bureaucrat&	Bureaucrat::operator -- () {
	++_grade;
	_verifyGrade();
	return (*this);
}

bool		Bureaucrat::operator <= (int const & rhs) {
	if (getGrade() >= rhs)
		return true;
	return false;
}

bool		Bureaucrat::operator >= (int const & rhs) {
	if (getGrade() <= rhs)
		return true;
	return false;
}

bool		Bureaucrat::operator < (int const & rhs) {
	if (getGrade() > rhs)
		return true;
	return false;
}

bool		Bureaucrat::operator > (int const & rhs) {
	if (getGrade() < rhs)
		return true;
	return false;
}


/*------------Stream output overload------------*/

std::ostream& operator << (std::ostream &os, Bureaucrat const & rhs){
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}



/*-----------Public member functions------------*/


int				Bureaucrat::getGrade() const {
	return (this->_grade);
}

std::string		Bureaucrat::getName() const {
	return (this->_name);
}

void			Bureaucrat::incrementGrade() {
	++(*this);
}

void			Bureaucrat::decrementGrade() {
	--(*this);
}

void			Bureaucrat::signForm(Form *form) {
	if (form->getSignedStatus() == true) {
		std::cout << "\e[0;31m" << this->getName() << " couldn't sign \"" << form->getName() << "\" because: ";
		throw(FormAlreadySignedException());
	}
	if (*this < form->getGradeToSign()) {
		std::cout << "\e[0;31m" << this->getName() << " couldn't sign \"" << form->getName() << "\" because: ";
		throw(Form::GradeTooHighException());
	}
	else {
		form->beSigned(*this);
		std::cout << green << this->getName() << " signed \"" << form->getName() << "\"" << std::endl << reset;
	}
}


/*-------------------Exceptions------------------*/


const char*		Bureaucrat::GradeTooLowException::what() const throw() {
	return "\e[0;31mNice try, but the grade is too damn low on that bureaucrat!!!\e[0m";
}

const char*		Bureaucrat::GradeTooHighException::what() const throw() {
	return "\e[0;31mNice try, but the grade is too damn high on that bureaucrat!!!\e[0m";
}

const char*		Bureaucrat::FormAlreadySignedException::what() const throw() {
	return "This form is already signed!!!";
}


/*-----------Private member functions-----------*/


void	Bureaucrat::_verifyGrade() {
	if (*this < 151)
		throw GradeTooLowException();
	else if (*this > 0)
		throw GradeTooHighException();
}

void	Bureaucrat::_setGrade(int grade) {
	this->_grade = grade;
}

