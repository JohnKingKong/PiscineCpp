/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:02:20 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/18 14:26:20 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"

int main() {

	std::cout << cyan << "First test: default constructor(no params), stream overload, decrement overload error" << std::endl;
	std::cout << reset;
	try {
		Bureaucrat	Robert;

		std::cout << green << Robert << reset << std::endl;
		std::cout << cyan << "Raise his grade using increment overload" << std::endl << reset;
		++Robert;
		std::cout << green << Robert << std::endl << reset;
		std::cout << cyan << "Trying to lower his grade two times(so its under the limit) using decrement overload" << std::endl << reset;
		--Robert;
		--Robert;
	}
	catch(const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}

	std::cout << cyan << "Second test: default constructor(with params), getname, getgrade, increment function error" << reset << std::endl;
	try {
		Bureaucrat	Paul("Paul", 1);

		std::cout << green << "bureaucrat name = " << Paul.getName() << ", and grade = " << Paul.getGrade() << std::endl << reset;
		std::cout << cyan << "Lowering his grade using decrement function" << reset << std::endl;
		Paul.decrementGrade();
		std::cout << green << "Bureaucrat name = " << Paul.getName() << ", and grade = " << Paul.getGrade() << reset << std::endl;
		std::cout << cyan << "Trying to raise his grade(two times so its over the limit) using increment function" << reset << std::endl;
		Paul.incrementGrade();
		Paul.incrementGrade();
	}
	catch (const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	std::cout << cyan << "Trying to init a bureaucrat with a too low grade" << reset << std::endl;
	try {
		Bureaucrat	Andre("Andre", 200);

		std::cout << "THIS IS NOT SUPPOSED TO PRINT" << std::endl;
	}
	catch (const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	std::cout << cyan << "Trying to init a bureaucrat with a too high grade" << reset << std::endl;
	try {
		Bureaucrat	Roger("Roger", -12);

		std::cout << "THIS IS NOT SUPPOSED TO SHOW" << std::endl;
	}
	catch (const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}