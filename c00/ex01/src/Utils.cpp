/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:32:41 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/08 18:49:40 by anonymous        ###   ########.fr       */
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
	std::cout << blue << "First Name : " << reset;
	std::getline(std::cin, infoContact[0]);
	std::cout << blue << "Last Name : " << reset;
	std::getline(std::cin, infoContact[1]);
	std::cout << blue << "Nickname : " << reset;
	std::getline(std::cin, infoContact[2]);
	std::cout << blue << "Phone Number : " << reset;
	std::getline(std::cin, infoContact[3]);
	std::cout << blue << "Darkest Secret : " << reset;
	std::getline(std::cin, infoContact[4]);
	for (int i = 0; i < 5; i++)
	{
		if (CheckForValidInput(infoContact[i], i) == false)
			return (false);
	}
	return (true);
}