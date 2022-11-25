/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:58 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/25 13:26:04 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.class.hpp"
#include "Exceptions.class.hpp"

int main()
{
	try {
		Conversion convert1("69");
		Conversion convert2("0");
		Conversion convert3("-inff");
		Conversion convert4("69.69f");
		// Conversion convert5("dsadas");

		std::cout << convert1 << std::endl;
		std::cout << convert2 << std::endl;
		std::cout << convert3 << std::endl;
		std::cout << convert4 << std::endl;
		// std::cout << convert5 << std::endl;

	}
	catch(const std::exception& exception){
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}
