/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:11 by jvigneau          #+#    #+#             */
/*   Updated: 2023/01/10 15:24:11 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.class.hpp"


/*---------Constructors and Destructors---------*/


Form::Form() :	_name("DEFAULT"), 
				_gradeToSign(150), 
				_gradeToUse(150) {

	_verifyGradeToUse();
	_verifyGradeToSign();
	_setSignedStatus(false);
	std::cout << purple << "Default form constructor(no params) called" << reset << std::endl;
}

Form::Form(std::string const name,
	int const gradeToSign,
	int const gradeToUse) :
				_name(name),
				_gradeToSign(gradeToSign),
				_gradeToUse(gradeToUse) {

	_verifyGradeToUse();
	_verifyGradeToSign();
	_setSignedStatus(false);
	std::cout << purple << "Default form constructor(with params) called" << reset << std::endl;
}

Form::Form(const Form& other) : 
				_name(other.getName()),
				_gradeToSign(other.getGradeToSign()),
				_gradeToUse(other.getGradeToUse()) {

	_verifyGradeToUse();
	_verifyGradeToSign();
	*this = other;
	std::cout << purple << "Copy form constructor called" << reset << std::endl;
}

Form::~Form() {
}



/*--------------Operators overload--------------*/


Form& Form::operator=(Form const & rhs) {
	this->_setSignedStatus(rhs.getSignedStatus());
	return *this;
}



/*------------Stream output overload------------*/

std::ostream& operator << (std::ostream &os, Form const & rhs) {
	os << rhs.getName() << " needs a grade of " << rhs.getGradeToSign();
	os << " or higher to sign it; a grade of " << rhs.getGradeToUse();
	os << " or higher to use it and the signed status of it is ";
	if (rhs.getSignedStatus() == false)
		os << "false";
	else
		os << "true";
	return os;
}


/*-----------Public member functions------------*/


std::string		Form::getName() const {
	return (this->_name);
}

int	Form::getGradeToUse() const {
	return (this->_gradeToUse);
}

int	Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

bool			Form::getSignedStatus() const {
	return (this->_signedForm);
}

void			Form::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		_setSignedStatus(true);
	else
		throw(GradeTooLowException());
}


/*-------------------Exceptions------------------*/


const char*		Form::GradeTooLowException::what() const throw() {
	return "\e[0;31mNice try, but the grade is too damn low on that form!!!\e[0m";
}

const char*		Form::GradeTooHighException::what() const throw() {
	return "\e[0;31mNice try, but the grade is too damn high on that form!!!\e[0m";
}


/*-----------Private member functions-----------*/

void		Form::_setSignedStatus(bool signedStatus) {
	this->_signedForm = signedStatus;
}

void		Form::_verifyGradeToUse() {
	if (this->_gradeToUse > 151)
		throw(GradeTooLowException());
	if (this->_gradeToUse < 0)
		throw(GradeTooHighException());
}

void		Form::_verifyGradeToSign() {
	if (this->_gradeToSign > 151)
		throw(Form::GradeTooLowException());
	if (this->_gradeToSign < 0)
		throw(GradeTooHighException());
}
