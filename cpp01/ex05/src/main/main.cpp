/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:26:00 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/08 17:41:18 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Harl.class.hpp"

int main()
{
	Harl	karenBot;

	std::cout << "Test de INFO" << std::endl;
	karenBot.complain("1");
	std::cout << std::endl;
	std::cout << "Test de DEBUG" << std::endl;
	karenBot.complain("0");
	std::cout << std::endl;
	std::cout << "Test de WARNING" << std::endl;
	karenBot.complain("2");
	std::cout << std::endl;
	std::cout << "Test de ERROR" << std::endl;
	karenBot.complain("3");
	std::cout << std::endl;
	std::cout << "Test de level trop haut" << std::endl;
	karenBot.complain("5");
	std::cout << std::endl;
	std::cout << "Test de level trop bas" << std::endl;
	karenBot.complain("-1");
	std::cout << std::endl;

	std::cout << "Test de tous un apres l'autre" << std::endl;
	karenBot.complain("-1000");
	std::cout << std::endl;
	karenBot.complain("0");
	std::cout << std::endl;
	karenBot.complain("1");
	std::cout << std::endl;
	karenBot.complain("2");
	std::cout << std::endl;
	karenBot.complain("3");
	std::cout << std::endl;
	karenBot.complain("420");
	std::cout << std::endl;

	return 0;
}