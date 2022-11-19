/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:29 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/19 15:16:43 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.class.hpp"


PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other){
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs){
	PresidentialPardonForm::<CHANGE_FUNC_NAME>(rhs.<CHANGE_FUNC_NAME>());
	return *this;
}


