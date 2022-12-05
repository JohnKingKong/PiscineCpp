/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.template.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:05:55 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/05 11:05:23 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*---------Constructors and Destructors---------*/

template  <typename T>
Array<T>::Array() {
	std::cout << "Default Constructor(no param) called" << std::endl;
	this->_size = 0;
	this->_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int size) {
	std::cout << "Constructor with param called" << std::endl;
	this->_array = new T[size];
	this->_size = size;
}

template <typename T>
Array<T>::Array(const Array& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_size = other._size;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T>::~Array() {
	if (this->_array)
		delete [] this->_array;
}



/*--------------Operators overload--------------*/

template <typename T>
Array<T> &	Array<T>::operator=(Array const & rhs) {
	this->_size = rhs._size;
	delete this->_array;
	this->_array = new T[rhs._size];

	for (unsigned int i = 0; i < rhs._size; i++)
		this->_array[i] = rhs._array[i];
}

template <typename T>
T &	Array<T>::operator[](std::size_t size) {
	if (static_cast<unsigned int>(size) > this->_size)
		throw(OutOfBoundAccessException());
	return this->_array[size]; 
}



/*-----------Public member functions------------*/

template <typename T>
unsigned int	Array<T>::getSize() const {
	return this->_size;
}

template <typename T>
T				*Array<T>::getArray() const {
	return this->_array;
}

/*-------------------Exceptions------------------*/

template <typename T>
const char* Array<T>::OutOfBoundAccessException::what() const throw() {
	return "\e[0;31mNice try, but you can't access this far in the array\e[0m";
}