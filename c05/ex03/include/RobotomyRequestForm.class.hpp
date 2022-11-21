/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:29 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/21 14:02:32 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.class.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class RobotomyRequestForm : public AForm {
	public:

		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);

		virtual void	execute(Bureaucrat const & executor) const;

	private:

		RobotomyRequestForm();

		std::string		_target;
};
