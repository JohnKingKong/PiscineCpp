/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:53:21 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/22 13:05:47 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.class.hpp"
#include <string>

class Intern {
	public:

		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(Intern const & rhs);

		AForm		*makeForm(std::string formName, std::string target);
		AForm*		checkForm(std::string formName, std::string target);

	private:

		AForm		*_makeShrubberyCreationForm(std::string target);
		AForm		*_makePresidentialPardonForm(std::string target);
		AForm		*_makeRobotomyRequestForm(std::string target);
		int			_checkValidFormName(std::string formName);

		AForm		*(Intern::*functionPointer[3])(std::string target);

};
