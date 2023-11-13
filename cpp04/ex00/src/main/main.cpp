/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/18 11:58:47 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"
#include "WrongCat.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"

int main()
{
	Animal* animal = new Animal;
	Cat		cat;
	Dog*		dog = new Dog;
	WrongCat* wrongCat = new WrongCat;

	cat.makeSound();
	animal->makeSound();
	dog->makeSound();
	wrongCat->makeSound();
	delete(animal);
	delete(dog);
	delete(wrongCat);

	Animal* meta = new Animal;
	Animal* j = new Dog;
	Cat* i = new Cat;
	WrongAnimal* wrongAnimal = new WrongAnimal;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	wrongAnimal->makeSound();
	delete(wrongAnimal);
	delete(meta);
	delete(j);
	delete(i);
	return 0;
}