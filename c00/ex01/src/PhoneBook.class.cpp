/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:51:06 by jvigneau          #+#    #+#             */
/*   Updated: 2022/10/10 14:34:23 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.class.hpp"
#include "../inc/Colors.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

int		PhoneBook::_index = 0;
int		PhoneBook::_numberOfContacts = 0;

int				PhoneBook::getNumberOfContacts() { return PhoneBook::_numberOfContacts ;};

int				PhoneBook::getIndex() { return PhoneBook::_index ;};

void			PhoneBook::getContact(int index) const {

	std::cout << cyan << "First Name :\t" << yellow << _contacts[index]->getFirstName() << std::endl;
	std::cout << cyan << "Last Name :\t" << yellow << _contacts[index]->getLastName() << std::endl;
	std::cout << cyan << "Nickname :\t" << yellow << _contacts[index]->getNickname() << std::endl;
	std::cout << cyan << "Phone Number :\t" << yellow << _contacts[index]->getPhoneNumber() << std::endl;
	std::cout << cyan << "Dark Secret :\t" << yellow <<_contacts[index]->getDarkSecret() << std::endl;
	std::cout << reset << std::endl << std::endl;
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
	std::cout << std::endl;
	std::cout << purple << "                 Contacts : " << cyan << std::endl << std::endl;
	std::cout << "|  Index  | F. Name | L. Name | N. Name |" << std::endl;
	std::cout << "|*********|*********|*********|*********|" << std::endl;
	for (int i = 1; i <= 8; i++) {
		if (i - 1 < PhoneBook::getNumberOfContacts()) {
			std::cout << "|        " << yellow << i << cyan << "|";
			showFirstName(i);
			showLastName(i);
			showNickname(i);
			std::cout << std::endl;
		}
		else {
			std::cout << "|        " << yellow << i << cyan << "|";
			std::cout << "         |         |         |" << std::endl;
		}
	}
	std::cout << cyan <<"|*********|*********|*********|*********|"<< reset << std::endl << std::endl;
}

void			PhoneBook::setPhoneBook(Contact *contact, int index) {
	if (index < 8 && index >= 0)
		this->_contacts[index] = contact;
}

void			PhoneBook::showFirstName(int i) {
	if (_contacts[i - 1]->getFirstName().size() >= 10) {
		std::cout << purple << _contacts[i - 1]->getFirstName().substr(0, 8) << ".";
		std::cout << cyan << "|";
	}
	else {
		for (int j = _contacts[i - 1]->getFirstName().size(); j <= 8; j++)
			std::cout << " ";
		std::cout << purple << _contacts[i - 1]->getFirstName().substr(0, 9);
		std::cout << cyan << "|";
	}
}

void			PhoneBook::showLastName(int i) {
	if (_contacts[i - 1]->getLastName().size() >= 10) {
		std::cout << purple << _contacts[i - 1]->getLastName().substr(0, 8) << ".";
		std::cout << cyan << "|";
	}
	else {
		for (int j = _contacts[i - 1]->getLastName().size(); j <= 8; j++)
			std::cout << " ";
		std::cout << purple << _contacts[i - 1]->getLastName().substr(0, 9);
		std::cout << cyan << "|";
	}
}

void			PhoneBook::showNickname(int i) {
	if (_contacts[i - 1]->getNickname().size() >= 10) {
		std::cout << purple << _contacts[i - 1]->getNickname().substr(0, 8) << ".";
		std::cout << cyan << "|";
	}
	else {
		for (int j = _contacts[i - 1]->getNickname().size(); j <= 8; j++)
			std::cout << " ";
		std::cout << purple << _contacts[i - 1]->getNickname().substr(0, 9);
		std::cout << cyan << "|";
	}
}
