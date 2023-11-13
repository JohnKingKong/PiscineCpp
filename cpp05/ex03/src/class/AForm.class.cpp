/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:11 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/22 12:01:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.class.hpp"


/*---------Constructors and Destructors---------*/


AForm::AForm() :	_name("DEFAULT"), 
				_gradeToSign(150), 
				_gradeToUse(150) {

	_verifyGradeToUse();
	_verifyGradeToSign();
	_setSignedStatus(false);
	std::cout << purple << "Default AForm constructor(no params) called" << reset << std::endl;
}

AForm::AForm(std::string const name,
	unsigned int const gradeToSign,
	unsigned int const gradeToUse) :
				_name(name),
				_gradeToSign(gradeToSign),
				_gradeToUse(gradeToUse) {

	_verifyGradeToUse();
	_verifyGradeToSign();
	_setSignedStatus(false);
	std::cout << purple << "Default AForm constructor(with params) called" << reset << std::endl;
}

AForm::AForm(const AForm& other) : 
				_name(other.getName()),
				_gradeToSign(other.getGradeToSign()),
				_gradeToUse(other.getGradeToUse()) {

	_verifyGradeToUse();
	_verifyGradeToSign();
	*this = other;
	std::cout << purple << "Copy AForm constructor called" << reset << std::endl;
}

AForm::~AForm() {
}



/*--------------Operators overload--------------*/


AForm& AForm::operator=(AForm const & rhs) {
	this->_setSignedStatus(rhs.getSignedStatus());
	return *this;
}



/*------------Stream output overload------------*/

std::ostream& operator << (std::ostream &os, AForm const & rhs) {
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


std::string		AForm::getName() const {
	return (this->_name);
}

unsigned int	AForm::getGradeToUse() const {
	return (this->_gradeToUse);
}

unsigned int	AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

bool			AForm::getSignedStatus() const {
	return (this->_signedAForm);
}

void			AForm::beSigned(Bureaucrat const & bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		_setSignedStatus(true);
	else
		throw(GradeTooLowException());
}


/*-------------------Exceptions------------------*/


const char*		AForm::GradeTooLowException::what() const throw() {
	return "\e[0;31mNice try, but the grade is too damn low on that form!!!\e[0m";
}

const char*		AForm::GradeTooHighException::what() const throw() {
	return "\e[0;31mNice try, but the grade is too damn high on that form!!!\e[0m";
}

const char*		AForm::FormNotSignedException::what() const throw() {
	return"\e[0;31mThis form is not signed, you can't use it!!!\e[0m";
}

const char*		AForm::FormNameInvalidException::what() const throw() {
	return "\e[0;31mThe name provided for the form isn't a recognised form name!!!\e[0m";
}

/*-----------Private member functions-----------*/

void		AForm::_setSignedStatus(bool signedStatus) {
	this->_signedAForm = signedStatus;
}

void		AForm::_verifyGradeToUse() {
	if ((int)this->_gradeToUse >= 151)
		throw(GradeTooLowException());
	if ((int)this->_gradeToUse <= 0)
		throw(GradeTooHighException());
}

void		AForm::_verifyGradeToSign() {
	if ((int)this->_gradeToSign >= 151)
		throw(AForm::GradeTooLowException());
	if ((int)this->_gradeToSign <= 0)
		throw(GradeTooHighException());
}
