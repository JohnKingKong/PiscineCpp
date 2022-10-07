/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:50:17 by jvigneau          #+#    #+#             */
/*   Updated: 2022/10/07 14:35:01 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.class.hpp"

Contact::Contact(std::string Infos[5]) {

	Contact::setFirstName(Infos[0]);
	Contact::setLastName(Infos[1]);
	Contact::setNickname(Infos[2]);
	Contact::setPhoneNumber(Infos[3]);
	Contact::setDarkSecret(Infos[4]);
}

Contact::~Contact() {}

std::string		Contact::getFirstName() const { return (this->_firstName );};
std::string		Contact::getLastName() const { return (this->_lastName );};
std::string		Contact::getNickname() const { return (this->_nickname ); };
std::string		Contact::getPhoneNumber() const { return (this->_phoneNumber ); };
std::string		Contact::getDarkSecret() const { return (this->_darkSecret ); };

void			Contact::setFirstName(std::string firstName) { this->_firstName = firstName; };
void			Contact::setLastName(std::string lastName) { this->_lastName = lastName; };
void			Contact::setNickname(std::string nickname) { this->_nickname = nickname; };
void			Contact::setPhoneNumber(std::string phoneNumber) { this->_phoneNumber = phoneNumber; };
void			Contact::setDarkSecret(std::string darkSecret) { this->_darkSecret = darkSecret; };
