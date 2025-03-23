/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:54:49 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/23 18:16:10 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKAGE_HPP
# define PACKAGE_HPP

# include "A.hpp"
# include "B.hpp"
# include "Base.hpp"
# include "C.hpp"
# include <cstdlib>
# include <ctime>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

Base	*generate(void);

void	identify(Base *p);
void	identify(Base &p);

#endif
