/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:09:44 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/23 17:43:47 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <iostream>
# include <stdint.h>

class Serializer
{
  private:
	Serializer();
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &src);
	~Serializer();

  public:
	static uintptr_t serialize(Data *data);
	static Data *deserialize(uintptr_t raw);
};

#endif
