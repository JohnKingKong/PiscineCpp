/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:32:41 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/10 14:59:44 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"

void			PrintError(int i) {
	std::cout<<red<<std::endl;
	switch (i) {
		case 0:
		std::cout << "Must enter a valid first name(minimum 2 letters long and only letters, space or `-`)" << std::endl; break;
		case 1:
		std::cout << "Must enter a valid last name(minimum 2 letters long and only letters, space or `-`)" << std::endl; break;
		case 2:
		std::cout << "Must enter a valid nickname(minimum 2 characters long)" << std::endl; break;
		case 3:
		std::cout << "Must enter a valid phone number(9 numbers long)" << std::endl; break;
		case 4:
		std::cout << "Must enter a valid secret(minimum 2 characters long)" << std::endl; break;
	}
	std::cout<<reset<<std::endl;
}

bool			CheckForValidInput(std::string infoContact, int i) {
	if (infoContact == "") {
		PrintError(i); return false;
	}
	for (int j = 0; j < (int)infoContact.size();j++) {
		if (i == 3 && (!isdigit(infoContact[j]) || infoContact.size() != 10)) {
			PrintError(i); return(false);
		}
		if ((infoContact.size() < 2)
			|| (i < 2 && !isalpha(infoContact[j]) && infoContact[j] != ' '
				&& infoContact[j] != '-')) {
			PrintError(i); return (false);
		}
	}
	return (true);
}

bool			PopulateContact(std::string infoContact[5]) {
	std::cout << std::endl;
	std::cout << green << "First Name : " << reset;
	std::getline(std::cin, infoContact[0]);
	std::cout << green << "Last Name : " << reset;
	std::getline(std::cin, infoContact[1]);
	std::cout << green << "Nickname : " << reset;
	std::getline(std::cin, infoContact[2]);
	std::cout << green << "Phone Number : " << reset;
	std::getline(std::cin, infoContact[3]);
	std::cout << green << "Darkest Secret : " << reset;
	std::getline(std::cin, infoContact[4]);
	for (int i = 0; i < 5; i++)
	{
		if (CheckForValidInput(infoContact[i], i) == false)
			return (false);
	}
	std::cout << yellow << "New contact added to the phonebook." \
		<< reset << std::endl << std::endl;
	return (true);
}

bool			checkValidIndex(std::string prompt, int numberOfContacts) {
	for (int i = 0; i < (int)prompt.size(); i++) {
		if (!isdigit(prompt[i]) || std::stoi(prompt) > 8 || std::stoi(prompt) == 0) {
			std::cout << red << "Invalid number" << std::endl; return false; }
		if (std::stoi(prompt) > numberOfContacts) {
			std::cout << red << "No contact at this index yet" << std::endl; return false ; }
	}
	return true;
}