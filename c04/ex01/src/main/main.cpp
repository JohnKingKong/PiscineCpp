/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:01:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/17 11:33:42 by jvigneau         ###   ########.fr       */
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

	std::cout << test.getType() << std::endl;
	test.makeSound();

	Cat *cat = new Cat;
	cat->makeSound();
	delete(cat);
	
	for (int i = 0; i < 10; i++)
		delete(animal[i]);
}