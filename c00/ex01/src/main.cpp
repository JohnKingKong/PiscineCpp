/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:35:05 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/10 14:38:59 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"

int				main(void)
{
	std::string			prompt = "";
	std::string			infoContact[5];
	int					numberOfContacts = 0;
	PhoneBook			book;
	Contact				*contacts[8];

	system("clear");
	std::cout << std::endl << std::endl;
	std::cout << cyan << "Yolo App: worst Phonebook in the game" << std::endl;
	std::cout << reset << std::endl << std::endl;
	while (std::cin.good())
	{
		std::cout << purple << "Choose what to do :" << std::endl;
		std::cout << green << "ADD: "<< yellow << "To add a new contact" << std::endl;
		std::cout << green << "SEARCH: " << yellow << "To search an existing contact" << std::endl;
		std::cout << green << "EXIT: "<< yellow << "To quit the program" << reset << std::endl;
		std::cout << purple << std:: endl << "Choice : " << reset;
		std::getline(std::cin, prompt);
		if (prompt == "ADD")
		{
			if (PopulateContact(infoContact))
			{
				if (numberOfContacts > 8)
					delete contacts[book.getIndex()];
				contacts[book.getIndex()] = new Contact(infoContact);
				book.addContact(contacts[book.getIndex()]);
				numberOfContacts++;
			}
		}
		else if (prompt == "SEARCH")
		{
			if (numberOfContacts == 0) {
				std::cout << red << std::endl \
				<< "There is no contact in your book, type ADD to add a new one." \
				<< std::endl << reset << std::endl;
				continue ;
			}
			book.showPhoneBook();
			std::cout << purple << "Enter the index of the contact thou wish to see : " << reset;
			std::getline(std::cin, prompt);
			std::cout << std::endl;
			if (checkValidIndex(prompt, numberOfContacts) == true)
				book.getContact(std::stoi(prompt) - 1);
		}
		else if (prompt == "EXIT")
			break ;
		else
			std::cout << red << std::endl << "Invalid choice" << reset << std::endl << std::endl;
	}
	return 0;
}
