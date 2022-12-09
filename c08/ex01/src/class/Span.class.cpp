/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:58:52 by jvigneau          #+#    #+#             */
/*   Updated: 2022/12/06 13:49:03 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"


Span::Span(){}

Span::Span(const Span& other){
	*this = other;
}

Span::~Span(){}

Span& Span::operator=(Span const & rhs){
	Span::<CHANGE_FUNC_NAME>(rhs.<CHANGE_FUNC_NAME>());
	return *this;
}


