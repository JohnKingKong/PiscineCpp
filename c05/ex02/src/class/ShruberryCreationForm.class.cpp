/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:29 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/19 15:16:51 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.class.hpp"


ShruberryCreationForm::ShruberryCreationForm(){}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm& other){
	*this = other;
}

ShruberryCreationForm::~ShruberryCreationForm(){}

ShruberryCreationForm& ShruberryCreationForm::operator=(ShruberryCreationForm const & rhs){
	ShruberryCreationForm::<CHANGE_FUNC_NAME>(rhs.<CHANGE_FUNC_NAME>());
	return *this;
}


