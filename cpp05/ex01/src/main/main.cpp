/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:02:20 by jvigneau          #+#    #+#             */
/*   Updated: 2023/01/10 15:16:08 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int main() {

	try {
		std::cout << cyan << "First test, form(no params), bureaucrat(no params)";
		std::cout << ", signform(copy constructor form), grade equal to grade to sign" << reset << std::endl;
		Form		Form1;
		Bureaucrat	Bob;

		Bob.signForm(&Form1);

		std::cout << cyan << "Second test, form(params), bureaucrat(params)";
		std::cout << ", signform(copy constructor form), grade higher to grade to sign";
		std::cout << reset << std::endl;

		Form		Form2("Demande de subvention", 10, 69);
		Bureaucrat	Paul("Paul", 5);

		Paul.signForm(&Form2);

		std::cout << cyan << "Third test, form(params), bureaucrat(params)";
		std::cout << ", signform(copy constructor form), grade too low to sign" << reset << std::endl;

		Form		Form3("Demande de Permis", 10, 69);
		Bureaucrat	Gaston("Gaston", 100);

		Gaston.signForm(&Form3);
	}
	catch(const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	try {
		std::cout << cyan << "Fourth test, form(params), bureaucrat(params)";
		std::cout << ", signform(copy constructor form), form already signed";
		std::cout << reset << std::endl;

		Form		Form4("Demande de crier", 42, 42);
		Bureaucrat	Jay("Jay", 42);

		Jay.signForm(&Form4);
		Jay.signForm(&Form4);
	}
	catch(const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	try {
		std::cout << cyan << "Fifth Test, form(params), grade too low to sign, grade ok to use";
		std::cout << reset << std::endl;

		Form	Form5("Demande de marriage", 420, 42);
	}
	catch(const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	try {
		std::cout << cyan << "Sixth Test, form(params), grade too high to sign, grade ok to use";
		std::cout << reset << std::endl;

		Form	Form5("Demande de divorce", -12, 42);
	}
	catch(const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	try {
		std::cout << cyan << "Seventh Test, form(params), grade ok to sign, grade too low to use";
		std::cout << reset << std::endl;

		Form	Form5("Demande de marriage", 42, 420);
	}
	catch(const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	try {
		std::cout << cyan << "Eight Test, form(params), grade ok to sign, grade too high to use";
		std::cout << reset << std::endl;

		Form	Form5("Demande de divorce", 42, -42);
	}
	catch(const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}
