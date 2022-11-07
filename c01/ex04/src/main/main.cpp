/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:37:02 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/07 15:06:30 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {

	if (argc != 4) {
		std::cout << "Ohoh! You need 3 parameters; the file to open, the string to search";
		std::cout << " and the string to replace." << std::endl;
		return 1;
	}

	std::string			fileName = argv[1];
	std::string			strToFind = argv[2];
	std::string			strToReplace = argv[3];
	std::ifstream		inFileStream(fileName);
	std::string			tempStr;
	size_t				index;

	if (!inFileStream.is_open()) {
		std::cout << "Ohoh! Could not find the infile!!" << std::endl; return 1;
	}

	std::ofstream		outFileStream(fileName + ".replace");

	if (!outFileStream.is_open()) {
		std::cout<<"Ohoh! Could not create the outfile"<<std::endl;
		return 1;
	}

	while (!inFileStream.eof()) {
		getline(inFileStream, tempStr);
		while (1) {
			index = tempStr.find(strToFind);
			if (index != std::string::npos) {
				tempStr.erase(index, strToFind.size());
				tempStr.insert(index, strToReplace);
			} else
				break;
		}
		outFileStream << tempStr << std::endl;
	}
	inFileStream.close();
	outFileStream.close();
}