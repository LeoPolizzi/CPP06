/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:58:23 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/21 19:50:29 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cmath>
# include <cstdlib>
# include <exception>
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>
# include <cerrno>


# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

enum e_type
{
	SPECIAL = 0,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID = -1
};

class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	ScalarConverter &operator=(ScalarConverter const &src);
	~ScalarConverter();

  public:
	static void convert(std::string const &input);
};

e_type	getType(std::string const &input);
void printSpecial(std::string const &input);

void convertChar(std::string const &input);
void convertInt(std::string const &input);
void convertFloat(std::string const &input);
void convertDouble(std::string const &input);

#endif
