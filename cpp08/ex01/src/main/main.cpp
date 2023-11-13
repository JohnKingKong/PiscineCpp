/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:58:52 by jvigneau          #+#    #+#             */
/*   Updated: 2023/01/14 15:38:31 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	Span sn = Span(10000);

	for (int i = 0; i < 10000; i++)
		sn.addNumber(i);

	Span sb = Span(10000);
	std::vector<int> temp = sn.getVector();

	sb.addNumber(temp.begin(), temp.end());

	std::cout << "Shortest span: " << sb.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sb.longestSpan() << std::endl;
	return 0;
}