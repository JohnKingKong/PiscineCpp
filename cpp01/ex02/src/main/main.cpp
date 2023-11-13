/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:59:32 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/09 16:21:11 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../../include/Colors.hpp"

int main() {

	std::string		brain = "HI THIS IS BRIAN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << cyan << "string = " << &brain << green << "    stringPTR = ";
	std::cout << stringPTR << purple << "    stringREF = " << &stringREF;
	std::cout << reset << std::endl << std::endl;

	std::cout << cyan << "string = " << brain << green << "    stringPTR = ";
	std::cout << *stringPTR << purple << "    stringREF = " << stringREF;
	std::cout << reset << std::endl << std::endl;

}