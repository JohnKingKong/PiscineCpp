/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:58 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/24 21:14:25 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.class.hpp"
#include "Exceptions.class.hpp"

int main()
{
	try {
		Conversion convert1("76.36");

		char a = (convert1);
		double b = (convert1);
		float c = (convert1);
		int d = (convert1);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;

	}
	catch(const std::exception& exception){
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}
