/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:29 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/21 14:46:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.class.hpp"

/*---------Constructors and Destructors---------*/


RobotomyRequestForm::RobotomyRequestForm() : 
			AForm("RobotomyRequestForm", 72, 45) {
	_target = "UNDEFINED";
	std::cout << purple << "RobotomyRequestForm constructor called" << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
			AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << purple << "RobotomyRequestForm constructor called" << reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
			AForm("RobotomyRequestForm", 72, 45) {
	std::cout << purple << "RobotomyRequestForm copy constructor called" << reset << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}



/*--------------Operators overload--------------*/


RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}



/*-------------NonMember static functions--------------*/


static void			doTheRobotomy(std::string target) {
	std::cout << yellow << "*BUZZZZZZZZZZZZZ* *CLING* *CLANG* *CLUNG* *BUZZZZZZZZZZ*" << std::endl;
	srand(time(NULL));
	std::cout << purple << "The technician are trying their hardest!!!" << reset << std::endl;
	sleep(2);
	if (rand() % 2 == 1){
		std::cout << "AND THEY SUCCEEDED!!! Aren't they the best!?!?!" << target;
		std::cout << " is as fresh and new as his first day on the job" << std::endl;
	}
	else {
		std::cout << "Welp.... sometimes... things doesn't go the way you wanted them..... " << target;
		std::cout << " sadly passsed away during the procedure..." << std::endl;
	}
}



/*-----------Public member functions------------*/


void			RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getSignedStatus() == false)
		throw(AForm::FormNotSignedException());
	if (executor.getGrade() > this->getGradeToUse()) {
		std::cout << red << executor.getName() << " couldn't execute the " << this->getName() << " because : ";
		throw(AForm::GradeTooHighException());
	}
	else
		doTheRobotomy(this->_target);
}

