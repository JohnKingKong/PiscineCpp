/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:11 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/18 16:33:39 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.class.hpp"


/*---------Constructors and Destructors---------*/


Form::Form() : _name("DEFAULT"), 
		_gradeToSign(150), 
		_gradeToUse(150) {
			_setSignedStatus(false);
}

Form::Form(std::string const name,
	unsigned int const gradeToSign,
	unsigned int const gradeToUse) :
		_name(name),
		_gradeToSign(gradeToSign),
		_gradeToUse(gradeToUse) {
			_setSignedStatus(false);
		}

Form::Form(const Form& other) : 
		_name(other.getName()),
		_gradeToSign(other.getGradeToSign()),
		_gradeToUse(other.getGradeToUse()) {
	*this = other;
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

unsigned int	Form::getGradeToUse() const {
	return (this->_gradeToUse);
}

unsigned int	Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

bool			Form::getSignedStatus() const {
	return (this->_signedForm);
}

void			Form::beSigned(Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		_setSignedStatus(true);
	else
		throw(Form::GradeTooLowException());
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

void		Form::_verifyGradeToUse(unsigned int grade) {
	if (grade <= this->_gradeToUse)
		
}
