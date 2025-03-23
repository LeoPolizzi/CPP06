/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:59:14 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/23 17:59:21 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "package.hpp"

Base *createA(void)
{
	return (new A);
}

Base *createB(void)
{
	return (new B);
}

Base *createC(void)
{
	return (new C);
}

Base *generate(void)
{
	Base* (*constructors[3])(void) = {createA, createB, createC};

	return (constructors[rand() % 3]());
}
