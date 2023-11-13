/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:01:01 by jvigneau          #+#    #+#             */
/*   Updated: 2023/01/04 11:42:45 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"
#include "A_Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"

int main()
{
	A_Animal *animal[10];

	for (int i = 0; i < 5; i++)
		animal[i] = new Cat;
	for (int i = 5; i < 10; ++i)
		animal[i] = new Dog;
	for (int i = 0; i < 10; ++i)
		animal[i]->makeSound();

	// A_Animal test("Snake");
	// std::cout << test.getType() << std::endl;
	// test.makeSound();

	Cat *cat = new Cat;
	cat->makeSound();
	delete(cat);

	for (int i = 0; i < 10; i++)
		delete(animal[i]);
}