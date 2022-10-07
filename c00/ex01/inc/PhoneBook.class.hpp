/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:51:06 by jvigneau          #+#    #+#             */
/*   Updated: 2022/10/07 14:19:46 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../inc/Contact.class.hpp"

class PhoneBook {

	public:
		PhoneBook();
		~PhoneBook();

		static int		getNumberOfContacts();
		static int		getIndex();
		void			getContact(int index) const;
		void			addContact(Contact *contact);
		void			showPhoneBook();
		
	private:
		Contact			*_contacts[8];
		static int		_index;
		static int		_numberOfContacts;

		void			setPhoneBook(Contact *contact, int index);
		void			showFirstName(int i);
		void			showLastName(int i);
		void			showNickname(int i);
};