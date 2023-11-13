/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:34:01 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/10 14:39:18 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Contact.class.hpp"
#include "./PhoneBook.class.hpp"
#include "./Colors.hpp"
#include <iostream>

void			PrintError(int i);
bool			CheckForValidInput(std::string infoContact, int i);
bool			PopulateContact(std::string infoContact[5]);
bool			checkValidIndex(std::string prompt, int numberOfContacts);

