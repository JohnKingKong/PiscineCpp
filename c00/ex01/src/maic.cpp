#include "../inc/Contact.class.hpp"
#include "../inc/PhoneBook.class.hpp"

bool			PopulateContact(std::string infoContact[5]){
	std::cout << "First Name :";
	std::getline(std::cin, infoContact[0]);
	std::cout << "Last Name :";
	std::getline(std::cin, infoContact[1]);
	std::cout << "Nickname :";
	std::getline(std::cin, infoContact[2]);
	std::cout << "Phone Number :";
	std::getline(std::cin, infoContact[3]);
	std::cout << "Darkest Secret :";
	std::getline(std::cin, infoContact[4]);
	for (int i = 0; i < 5; i++)
	{
		if (infoContact[i] == "")
		{
			std::cout << "Must enter a valid information" << std::endl;
			return (false);
		}
	}
	return (true);
}


int				main(void)
{
	std::string			prompt = "";
	std::string			infoContact[5];
	int					numberOfContacts = 0;
	PhoneBook			book;
	Contact				*contacts[8];

	std::cout << "Yolo App: worst Phonebook in the game" << std::endl << std::endl;
	while (true)
	{
		std::cout << "Choose what to do :" << std::endl;
		std::cout << "ADD; To add a new contact" << std::endl;
		std::cout << "SEARCH; To search an existing contact" << std::endl;
		std::cout << "EXIT; To quit the program" << std::endl;
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
	}
	return 0;
}