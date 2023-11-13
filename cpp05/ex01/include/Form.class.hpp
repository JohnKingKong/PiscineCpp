/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:11 by jvigneau          #+#    #+#             */
/*   Updated: 2023/01/10 15:19:08 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.class.hpp"

class Form {
	public:

		Form();
		Form(std::string const name,
			int const gradeToSign,
			int const gradeToUse);
		Form(const Form& other);
		~Form();

		Form& operator=(Form const & rhs);

		std::string			getName() const;
		int					getGradeToUse() const;
		int					getGradeToSign() const;
		bool				getSignedStatus() const;
		void				beSigned(Bureaucrat & bureaucrat);


		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public : 
			virtual const char* what() const throw();
		};

	private:

		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToUse;
		bool				_signedForm;

		void				_setSignedStatus(bool signedStatus);
		void				_verifyGradeToSign();
		void				_verifyGradeToUse();
};
		std::ostream& operator << (std::ostream &os, Form const & rhs);
