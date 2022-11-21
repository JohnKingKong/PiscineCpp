/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:53:45 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/21 15:05:49 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.class.hpp"

Intern::Intern() {
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

Form*		Intern::makeForm(std::string formName, std::string target) {
	checkValidFormName(formName);

}





checker si cest un des trois forms, si non throw exception
retourner un pointeur sur fonction vers create le form du bon nom
