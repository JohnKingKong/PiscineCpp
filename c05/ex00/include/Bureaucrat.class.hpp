/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:02:20 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/18 13:46:13 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Colors.hpp"

class Bureaucrat {

	public:

		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		virtual ~Bureaucrat();


		Bureaucrat& operator=(Bureaucrat const & rhs);
		Bureaucrat& operator++();
		Bureaucrat& operator--();


		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public : 
			virtual const char* what() const throw();
		};


		std::string			getName() const;
		unsigned int		getGrade() const;
		void				incrementGrade();
		void				decrementGrade();


	private:

		std::string const	_name;
		unsigned int		_grade;


		void		_verifyGrade(unsigned int grade);
		void		_setGrade(unsigned int grade);

};

		std::ostream&	operator << (std::ostream &os, Bureaucrat const & rhs);