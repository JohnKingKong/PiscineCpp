/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:11 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/22 12:00:17 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.class.hpp"

class AForm {
	public:

		AForm();
		AForm(std::string const name,
			unsigned int const gradeToSign,
			unsigned int const gradeToUse);
		AForm(const AForm& other);
		virtual ~AForm();

		AForm& operator=(AForm const & rhs);

		std::string			getName() const;
		unsigned int		getGradeToUse() const;
		unsigned int		getGradeToSign() const;
		bool				getSignedStatus() const;
		void				beSigned(Bureaucrat const & bureaucrat);

		virtual void	execute(Bureaucrat const & executor) const = 0;


		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public : 
			virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class FormNameInvalidException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

	private:

		std::string const	_name;
		unsigned int const	_gradeToSign;
		unsigned int const	_gradeToUse;
		bool				_signedAForm;

		void				_setSignedStatus(bool signedStatus);
		void				_verifyGradeToSign();
		void				_verifyGradeToUse();
};
		std::ostream& operator << (std::ostream &os, AForm const & rhs);
