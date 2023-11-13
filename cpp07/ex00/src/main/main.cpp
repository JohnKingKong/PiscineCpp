/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:24:39 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/26 13:06:51 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ArithmeticBase.template.hpp"
#include <iostream>

int main() {
	std::cout << std::fixed;
	std::cout.precision(2);

	int		first = 42;
	int		second = 69;

	float	ffirst = 42.0f;
	float	fsecond = 69.0f;

	double	dfirst = 42.0;
	double	dsecond = 69.0;

	char	cfirst = 'A';
	char	csecond = 'Z';

	std::string	sfirst = "AAAAA";
	std::string ssecond = "BBBBB";

	std::cout << "first int = " << first << " and second int = " << second << std::endl;
	std::cout << "swapping int" << std::endl;
	swap<int>(first,second);
	std::cout << "first int = " << first << " and second int = " << second << std::endl;
	std::cout << std::endl;
	std::cout << "first float = " << ffirst << "f and second float = " << fsecond <<"f" << std::endl;
	std::cout << "swapping float" << std::endl;
	swap<float>(ffirst, fsecond);
	std::cout << "first float = " << ffirst << "f and second float = " << fsecond << "f" << std::endl;
	std::cout << std::endl;
	std::cout << "first double = " << dfirst << " and second double = " << dsecond << std::endl;
	std::cout << "swapping double" << std::endl;
	swap<double>(dfirst, dsecond);
	std::cout << "first double = " << dfirst << " and second double = " << dsecond << std::endl;
	std::cout << std::endl;
	std::cout << "first char = " << cfirst << " and second char = " << csecond << std::endl;
	std::cout << "swapping char" << std::endl;
	swap<char>(cfirst, csecond);
	std::cout << "first char = " << cfirst << " and second char = " << csecond << std::endl;
	std::cout << std::endl;
	std::cout << "first string = " << sfirst << " and second string = " << ssecond << std::endl;
	std::cout << "swapping string" << std::endl;
	::swap<std::string>(sfirst, ssecond);
	std::cout << "first string = " << sfirst << " and second string = " << ssecond << std::endl;
	std::cout << std::endl;

	std::cout << "min int = " << min(first, second) << " and the max = " << max(first,second) << std::endl;
	std::cout << std::endl;

	std::cout << "min float = " << min(ffirst,fsecond) << "f and the max = " << max(ffirst,fsecond) << "f" << std::endl;
	std::cout << std::endl;

	std::cout << "min double = " << min(dfirst,dsecond) << " and the max = " << max(dfirst,dsecond) << std::endl;
	std::cout << std::endl;

	std::cout << "min char = " << min(cfirst, csecond) << " and the max = " << max(cfirst, csecond) << std::endl;
	std::cout << std::endl;

	std::cout << "min string = " << ::min(sfirst,ssecond) << " and the max = " << ::max(sfirst,ssecond) << std::endl;
	return 0;
}