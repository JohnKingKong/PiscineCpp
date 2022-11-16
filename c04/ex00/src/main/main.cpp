/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/15 17:42:47 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.class.hpp"
#include "WrongCat.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"

int main()
{
	Cat* animal = new Cat;
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
	return 0;
}