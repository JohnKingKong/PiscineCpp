/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:35:05 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/08 19:09:19 by anonymous        ###   ########.fr       */
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
	std::cout << "Yolo App: worst Phonebook in the game" << std::endl;
	std::cout << std::endl << std::endl;
	while (true)
	{
		std::cout << purple << "Choose what to do :" << std::endl;
		std::cout << blue << "ADD: "<< yellow << "To add a new contact" << std::endl;
		std::cout << blue << "SEARCH: " << yellow << "To search an existing contact" << std::endl;
		std::cout << blue << "EXIT: "<< yellow << "To quit the program" << reset << std::endl;
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
				<< std::endl << std::endl;
				continue ;
			}
			book.showPhoneBook();
		}
	}
	return 0;
}