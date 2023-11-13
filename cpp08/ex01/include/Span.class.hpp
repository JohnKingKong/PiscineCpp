/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:58:52 by jvigneau          #+#    #+#             */
/*   Updated: 2023/01/14 15:33:01 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>

class Span {
	public:

		Span(unsigned int size);
		Span(const Span& other);
		~Span();

		Span& operator=(Span const & rhs);

		class SizeLimitReachedException : std::exception {
			public:
				virtual const char* what() const throw();
		};

		class SizeTooSmallException : std::exception {
			public:
				virtual const char* what() const throw();
		};

		void				addNumber(int value);
		void				addNumber(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end);
		int					shortestSpan() const;
		int					longestSpan() const;

		unsigned int		getSize() const;
		std::vector<int>	getVector() const;

	private:
		Span();

		const unsigned int			_size;
		std::vector<int>			_vector;
};
