/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:10:31 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/21 18:12:00 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	(void)src; // Nothing to copy in this class
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::convert(std::string const &input)
{
	e_type type = getType(input);

	switch (type)
	{
		case (0):
			printSpecial(input);
			break;
		case (1):
			convertChar(input);
			break;
		case (2):
			convertInt(input);
			break;
		case (3):
			convertFloat(input);
			break;
		case (4):
			convertDouble(input);
			break;
		default:
			std::cout << "Error: Invalid input" << std::endl;
			break;
	}

}
