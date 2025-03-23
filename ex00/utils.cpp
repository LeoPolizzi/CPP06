/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:12:03 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/21 19:53:37 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

e_type	getType(std::string const &input)
{
	size_t		i;
	bool	hasDot;
	bool	hasDigitAfterDot;

	i = 0;
	if (input.length() == 1 && !isdigit(input[0]))
		return (CHAR);
	else if (input == "-inff" || input == "+inff" || input == "nanf" || input == "-inf" || input == "+inf" || input == "nan")
		return (SPECIAL);
	if (input[i] == '-' || input[i] == '+')
		i++;
	hasDot = false;
	hasDigitAfterDot = false;
	while (i < input.length())
	{
		if (isdigit(input[i]))
		{
			if (hasDot)
				hasDigitAfterDot = true;
		}
		else if (input[i] == '.')
		{
			if (hasDot)
				return (INVALID);
			hasDot = true;
		}
		else if (input[i] == 'f' && i == input.length() - 1 && hasDot
			&& hasDigitAfterDot)
			return (FLOAT);
		else
			return (INVALID);
		i++;
	}
	if (hasDot)
		return (hasDigitAfterDot ? DOUBLE : INVALID);
	return (INT);
}

void	printSpecial(std::string const &input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: +inff" << std::endl;
		std::cout << "Double: +inf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: -inff" << std::endl;
		std::cout << "Double: -inf" << std::endl;
	}
}

void	convertChar(std::string const &input)
{
	char	c;
	int		i;
	float	f;
	double	d;

	c = input[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	if (isprint(c))
		std::cout << "Char: " << c << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << f << "f" << std::endl;
	std::cout << "Double: " << d << std::endl;
}

void	convertInt(std::string const &input)
{
	long	longVal;
	int		i;
	char	c;
	float	f;
	double	d;

	longVal = std::strtol(input.c_str(), NULL, 10);
	i = static_cast<int>(longVal);
	c = static_cast<char>(longVal);
	if (isprint(c))
		std::cout << "Char: " << c << std::endl;
	else if (i >= 0 && i <= 127)
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: Impossible" << std::endl;
	if (longVal < MIN_INT || longVal > MAX_INT || errno == ERANGE)
		std::cout << "Int: Overflow" << std::endl;
	else
		std::cout << "Int: " << i << std::endl;
	errno = 0;
	d = std::strtod(input.c_str(), NULL);
	f = static_cast<float>(d);
	if (d < MIN_FLOAT || d > MAX_FLOAT || errno == ERANGE)
		std::cout << "Float: Overflow" << std::endl;
	else
		std::cout << "Float: " << f << "f" << std::endl;
	if (d < MIN_DOUBLE || d > MAX_DOUBLE || errno == ERANGE)
		std::cout << "Double: Overflow" << std::endl;
	else
		std::cout << "Double: " << d << std::endl;
}

void	convertFloat(std::string const &input)
{
	double	dValue;
	float	f;
	int		i;
	char	c;

	dValue = std::strtod(input.c_str(), NULL);
	f = static_cast<float>(dValue);
	i = static_cast<int>(f);
	c = static_cast<char>(f);
	if (isprint(c))
		std::cout << "Char: " << c << std::endl;
	else if (f >= 0 && f <= 127)
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: Impossible" << std::endl;
	if (dValue < MIN_INT || dValue > MAX_INT || errno == ERANGE)
		std::cout << "Int: Overflow" << std::endl;
	else
		std::cout << "Int: " << i << std::endl;
	if (dValue < MIN_FLOAT || dValue > MAX_FLOAT || errno == ERANGE)
		std::cout << "Float: Overflow" << std::endl;
	else
		std::cout << "Float: " << f << "f" << std::endl;
	if (errno == ERANGE)
		std::cout << "Double: Overflow" << std::endl;
	else
		std::cout << "Double: " << dValue << std::endl;
}

void	convertDouble(std::string const &input)
{
	double	d;
	float	f;
	int		i;
	char	c;

	d = std::strtod(input.c_str(), NULL);
	f = static_cast<float>(d);
	i = static_cast<int>(d);
	c = static_cast<char>(d);
	if (isprint(c))
		std::cout << "Char: " << c << std::endl;
	else if (d >= 0 && d <= 127)
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: Impossible" << std::endl;
	if (d < MIN_INT || d > MAX_INT || errno == ERANGE)
		std::cout << "Int: Overflow" << std::endl;
	else
		std::cout << "Int: " << i << std::endl;
	if (d < MIN_FLOAT || d > MAX_FLOAT || errno == ERANGE)
		std::cout << "Float: Overflow" << std::endl;
	else
		std::cout << "Float: " << f << "f" << std::endl;
	if (errno == ERANGE)
		std::cout << "Double: Overflow" << std::endl;
	else
		std::cout << "Double: " << d << std::endl;
}
