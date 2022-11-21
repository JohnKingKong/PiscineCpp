/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:53:21 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/21 15:05:47 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Intern {
	public:

		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(Intern const & rhs);

		*Form	makeForm(std::string formName, std::string target);
	private:
};
