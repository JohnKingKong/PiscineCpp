/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:02:20 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/18 16:00:49 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"



/*---------Constructors and Destructors---------*/


Bureaucrat::Bureaucrat() : _name("DEFAULT") {
	_setGrade(150);
	std::cout << purple << "Default constructor(no params) called" << reset << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	_verifyGrade(grade);
	_setGrade(grade);
	std::cout << purple << "Default constructor(with params) called" << reset << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
	*this = other;
	std::cout << purple << "Copy constructor called" << reset << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout  << yellow << "Default destructor called" << reset << std::endl;;
}



/*--------------Operators overload--------------*/


Bureaucrat& Bureaucrat::operator = (Bureaucrat const & rhs){
	Bureaucrat::_setGrade(rhs.getGrade());
	return *this;
}

Bureaucrat& Bureaucrat::operator ++ () {
	_verifyGrade(this->_grade - 1);
	--_grade;
	return (*this);
}

Bureaucrat& Bureaucrat::operator -- () {
	_verifyGrade(this->_grade + 1);
	++_grade;
	return (*this);
}


/*------------Stream output overload------------*/

std::ostream& operator << (std::ostream &os, Bureaucrat const & rhs){
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}



/*-----------Public member functions------------*/


unsigned int	Bureaucrat::getGrade() const {
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

void			Bureaucrat::signForm(Form form) {
	std::cout << form << std::endl;
}


/*-------------------Exceptions------------------*/


const char*		Bureaucrat::GradeTooLowException::what() const throw() {
	return "\e[0;31mNice try, but the grade is too damn low!!!\e[0m";
}

const char*		Bureaucrat::GradeTooHighException::what() const throw() {
	return "\e[0;31mNice try, but the grade is too damn high!!!\e[0m";
}



/*-----------Private member functions-----------*/


void	Bureaucrat::_verifyGrade(unsigned int grade) {
	if (grade >= 151)
		throw GradeTooLowException();
	else if (grade <= 0)
		throw GradeTooHighException();
}

void	Bureaucrat::_setGrade(unsigned int grade) {
	this->_grade = grade;
}

