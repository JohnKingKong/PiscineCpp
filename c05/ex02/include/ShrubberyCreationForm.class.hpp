/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:29 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/19 16:38:38 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.class.hpp"

class ShrubberyCreationForm : public AForm {
	public:

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rhs);

		virtual void	execute(Bureaucrat const & executor) const;

	private:

		ShrubberyCreationForm();

		std::string _target;

};
