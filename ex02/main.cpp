/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:58:38 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/23 18:15:57 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "package.hpp"

int main()
{
	srand(time(NULL));

	Base *p1 = generate();
	Base *p2 = generate();
	Base *p3 = generate();
	Base *p4 = generate();
	Base *p5 = generate();

	Base &p1_ref = *p1;
	Base &p2_ref = *p2;
	Base &p3_ref = *p3;
	Base &p4_ref = *p4;
	Base &p5_ref = *p5;

	std::cout << GREEN "Identifying 5 random classes by pointers" RESET "\n" << std::endl;

	identify(p1);
	identify(p2);
	identify(p3);
	identify(p4);
	identify(p5);

	std::cout << "\n" GREEN "Identifying 5 random classes by references" RESET "\n" << std::endl;

	identify(p1_ref);
	identify(p2_ref);
	identify(p3_ref);
	identify(p4_ref);
	identify(p5_ref);

	std::cout << "\n" RED "Deleting 5 random classes" RESET "\n" << std::endl;

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
}
