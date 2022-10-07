/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:51:06 by jvigneau          #+#    #+#             */
/*   Updated: 2022/10/07 14:26:23 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.class.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

int	PhoneBook::_index = 0;
int PhoneBook::_numberOfContacts = 0;

int		PhoneBook::getNumberOfContacts() { return PhoneBook::_numberOfContacts ;};

int		PhoneBook::getIndex() { return PhoneBook::_index ;};

void			PhoneBook::getContact(int index) const {

	std::cout << "First Name :\t" << _contacts[index]->getFirstName() << std::endl;
	std::cout << "Last Name :\t" << _contacts[index]->getLastName() << std::endl;
	std::cout << "Nickname :\t" << _contacts[index]->getNickname() << std::endl;
	std::cout << "Phone Number :\t" << _contacts[index]->getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret :\t" << _contacts[index]->getDarkSecret() << std::endl;
}

void			PhoneBook::addContact(Contact *contact) {
	if (PhoneBook::getIndex() >= 8)
		PhoneBook::_index = 0;
	PhoneBook::setPhoneBook(contact, PhoneBook::getIndex());
	PhoneBook::_index++;
	if (PhoneBook::getNumberOfContacts() < 8)
		PhoneBook::_numberOfContacts++;
}

void			PhoneBook::showPhoneBook() {
	for (int i = 0; i <= 8; i++)
	{
		if (i - 1 < PhoneBook::getNumberOfContacts()) {
			std::cout << "|" << i - 1 << "|";
			showFirstName(i);
			showLastName(i);
			showNickname(i);
			std::cout << std::endl;
		}
		else
			std::cout << "|                                |" << std::endl;
	}
}

void			PhoneBook::setPhoneBook(Contact *contact, int index) {
	if (index < 8 && index >= 0)
		this->_contacts[index] = contact;
}

void			PhoneBook::showFirstName(int i) {
	std::cout << _contacts[i - 1]->getFirstName().substr(0, 6);
	if (_contacts[i - 1]->getFirstName().size() >= 7)
		std::cout << ". |";
	else {
		for (int j = _contacts[i - 1]->getFirstName().size(); j <= 7; j++)
			std::cout << " ";
		std::cout << "|";
	}
}

void			PhoneBook::showLastName(int i) {
	std::cout << _contacts[i - 1]->getLastName().substr(0, 6);
	if (_contacts[i - 1]->getLastName().size() >= 7)
		std::cout << ". |";
	else {
		for (int j = _contacts[i - 1]->getLastName().size(); j <= 7; j++)
			std::cout << " ";
		std::cout << "|";
	}
}

void			PhoneBook::showNickname(int i) {
	std::cout << _contacts[i - 1]->getNickname().substr(0, 6);
	if (_contacts[i - 1]->getNickname().size() >= 7)
		std::cout << ". |";
	else {
		for (int j = _contacts[i - 1]->getNickname().size(); j <= 7; j++)
			std::cout << " ";
		std::cout << "|";
	}
}
