/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:50:17 by jvigneau          #+#    #+#             */
/*   Updated: 2022/10/08 17:41:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Contact {
	public:

		Contact(std::string Infos[5]);
		~Contact();
		
		std::string			getFirstName() const;
		std::string			getLastName() const;
		std::string			getNickname() const;
		std::string			getPhoneNumber() const;
		std::string			getDarkSecret() const;
		void				setFirstName(std::string firstName);
		void				setLastName(std::string lastName);
		void				setNickname(std::string nickname);
		void				setPhoneNumber(std::string phoneNumber);
		void				setDarkSecret(std::string darkSecret);

	private:
		std::string			_firstName;
		std::string			_lastName;
		std::string			_nickname;
		std::string			_phoneNumber;
		std::string			_darkSecret;
};