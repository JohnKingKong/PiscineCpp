/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:58:52 by jvigneau          #+#    #+#             */
/*   Updated: 2023/01/14 15:33:28 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"


Span::Span() : _size(0) {
}

Span::Span(unsigned int size) : _size(size) {
}

Span::Span(const Span& other) : _size(other.getSize()) {
	this->_vector = other.getVector();
}

Span::~Span(){}

Span& Span::operator=(Span const & rhs){
	if (this != &rhs) {
		if (this->_size < rhs.getSize())
			this->_vector = std::vector<int>(rhs.getVector());
		else
			throw SizeLimitReachedException();
	}
	return *this;
}



void	Span::addNumber(int value) {
	if (_vector.size() < this->_size)
		_vector.push_back(value);
	else
		throw SizeLimitReachedException();
}


void	Span::addNumber(const std::vector<int>::iterator &begin,const std::vector<int>::iterator &end) {
	int	distance = std::distance(begin, end);
	if (distance > static_cast<int>(_size - _vector.size()))
		throw SizeLimitReachedException();
	else
		_vector.insert(_vector.end(), begin, end);
}


int		Span::shortestSpan() const {
	std::vector<int>	tempVectorSorted;
	int					shortestSpan;
	int					temp;

	if (this->_size < 2)
		throw SizeTooSmallException();

	tempVectorSorted = this->_vector;
	std::sort(tempVectorSorted.begin(), tempVectorSorted.end());

	shortestSpan = tempVectorSorted[1] - tempVectorSorted[0];

	for(std::vector<int>::iterator i = tempVectorSorted.begin();
			i != tempVectorSorted.end() - 1;
			i++) {
		temp = *(i + 1) - *i;
		if (temp < shortestSpan)
			shortestSpan = temp;
	}
	return shortestSpan;
}

int		Span::longestSpan() const {
	std::vector<int>			tempVectorSorted;
	int							longestSpan;

	if (this->_size < 2)
		throw SizeTooSmallException();

	tempVectorSorted = this->_vector;
	std::sort(tempVectorSorted.begin(), tempVectorSorted.end());

	longestSpan = *(tempVectorSorted.end() - 1) - *(tempVectorSorted.begin());

	return longestSpan;
}

unsigned int		Span::getSize() const {
	return this->_size;
}

std::vector<int>		Span::getVector() const {
	return this->_vector;
}

const char*		Span::SizeLimitReachedException::what() const throw() {
	return "\e[0;31mThe Size limit has been reached!\e[0m";
}

const char*		Span::SizeTooSmallException::what() const throw() {
	return "\e[0;31mThe size is too small to do the function!\e[0m";
}