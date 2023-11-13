/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:01:47 by jvigneau          #+#    #+#             */
/*   Updated: 2022/10/03 15:56:04 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	char *temp;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int a = 1; a <= argc - 1; a++)
		{
			temp = argv[a];
			for (int i = 0; argv[a][i]; i++)
				temp[i] = toupper(temp[i]);
			std::cout << temp;
		}
	}
	std::cout << std::endl;
}