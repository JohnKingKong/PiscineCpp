/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:58 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/25 15:15:38 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.class.hpp"
#include "Exceptions.class.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "You gotta put a value to convert" << std::endl;
		return 0;
	}
	try {
		Conversion convert1(argv[1]);

		std::cout << convert1 << std::endl;
	}
	catch(const std::exception& exception){
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}
