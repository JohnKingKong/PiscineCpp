/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:29 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/21 13:13:37 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.class.hpp"

class PresidentialPardonForm : public AForm {
	public:

		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm& operator=(PresidentialPardonForm const & rhs);

		virtual void	execute(Bureaucrat const & executor) const;

	private:

		PresidentialPardonForm();

		std::string		_target;
};
