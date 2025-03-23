/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:21:04 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/23 17:43:37 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

int	main(void)
{
	Data *data = new Data;
	data->type = "test";
	data->value = 42;

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << GREEN "Pointer values:\n" RESET << std::endl;

	std::cout << "Decimal raw serialized data: " << raw << std::endl;
	std::cout << "Hexadecimal raw serialized data: 0x" << std::hex << raw << std::dec << std::endl;
	std::cout << "Data pointer: " << data << std::endl;
	std::cout << "Serialized data pointer: " << serialized << std::endl;

	std::cout << GREEN "\nData structure content:\n" RESET << std::endl;

	std::cout << "Data type: " << data->type << std::endl;
	std::cout << "Data value: " << data->value << std::endl;
	std::cout << "Serialized data type: " << serialized->type << std::endl;
	std::cout << "Serialized data value: " << serialized->value << std::endl;

	delete data;
}
