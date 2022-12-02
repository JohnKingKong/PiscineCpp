/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.template.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:05:55 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/02 17:33:21 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template  <typename T>
Array<T>::Array() {
	std::cout << "Default Constructor(no param) called" << std::endl;
	this->_array = new T();
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
	this->_array = new T[other._size];
	for (unsigned int i = 0; i < other._size; i++)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T> & Array<T>::operator=(Array const & rhs) {
	this->_size = rhs._size;
	delete this->_array;
	this->_array = new T[rhs._size];
	for (unsigned int i = 0; i < rhs._size; i++)
		this->_array[i] = rhs._array[i];
}

template <typename T>
T & Array<T>::operator[](std::size_t size) {
	if (static_cast<unsigned int>(size) > this->_size)
	throw(std::exception());
	return this->_array[size];
}

template <typename T>
Array<T>::~Array() {
	if (this->_array)
		delete [] this->_array;
}

template <typename T>
unsigned int Array<T>::getSize() const {
	return this->_size;
}

template <typename T>
T	* Array<T>::getArray() const {
	return this->_array;
}