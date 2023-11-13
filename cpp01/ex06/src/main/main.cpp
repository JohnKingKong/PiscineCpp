/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:26:00 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/08 18:08:51 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Harl.class.hpp"

int main(int argc, char *argv[]){
	Harl	karenBot;

	if (argc != 2){
		std::cout << "Strangely, you need something to complain about" << std::endl;
		return 1;
	}
	karenBot.filter(argv[1]);
	return 0;
}