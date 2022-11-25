/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:29:52 by jvigneau          #+#    #+#             */
/*   Updated: 2022/11/25 15:41:39 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.class.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include "A.class.hpp"
#include "B.class.hpp"
#include "C.class.hpp"

Base	*generate();
void	identify(Base* ptr);
void	identify(Base& ptr);