/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:01:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/16 12:52:38 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"
#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"

int main()
{
	Animal *animal[10];
	Animal test("Snake");

	for (int i = 0; i < 5; i++)
		animal[i] = new Cat;
	for (int i = 5; i < 10; ++i)
		animal[i] = new Dog;
	for (int i = 0; i < 10; ++i)
		animal[i]->makeSound();
	test.makeSound();
	std::cout << test.getType() << std::endl;
	for (int i = 0; i < 10; i++)
		delete(animal[i]);
}