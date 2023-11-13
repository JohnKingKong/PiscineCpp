/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:02:20 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/21 12:51:33 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Colors.hpp"

class	AForm;

class Bureaucrat {

	public:

		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		virtual ~Bureaucrat();


		Bureaucrat& operator=(Bureaucrat const & rhs);
		Bureaucrat& operator++();
		Bureaucrat& operator--();
		bool		operator<=(unsigned int const & rhs);
		bool		operator<(unsigned int const & rhs);
		bool		operator>=(unsigned int const & rhs);
		bool		operator>(unsigned int const & rhs);


		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public : 
			virtual const char* what() const throw();
		};
		class FormAlreadySignedException : public std::exception {
			public :
			virtual const char* what() const throw();
		};


		std::string			getName() const;
		unsigned int		getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm & form);
		void				executeForm(AForm const & form);

	private:

		std::string const	_name;
		unsigned int		_grade;


		void		_verifyGrade();
		void		_setGrade(unsigned int grade);

};

		std::ostream& operator << (std::ostream &os, Bureaucrat const & rhs);