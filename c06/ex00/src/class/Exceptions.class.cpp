/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:53:24 by anonymous         #+#    #+#             */
/*   Updated: 2022/11/23 17:07:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.class.hpp"


const char			*Exceptions::WrongInputException::what() const throw() {
		return "\e[0;31mThe converter takes a string as a param, dont forget the \"\" and that its not empty\e[0m";
}