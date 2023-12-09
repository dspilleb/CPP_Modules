/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:21:39 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 14:05:36 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;


void test_death( void )
{
	cout << "----TEST DEATH----" << std::endl;
	{
		ClapTrap test_death ("test_death");

		test_death.takeDamage(1);
		test_death.attack("42");
		test_death.takeDamage(9);
		test_death.attack("42");
		test_death.beRepaired(19);
		test_death.takeDamage(19);
	}
	cout << "------------------" << std::endl;
}

void test_energy( void )
{
	cout << "----TEST ENERGY----" << std::endl;
	{
		ClapTrap test_energy ("test_energy");

		for (int i = 0; i < 11; i++)
			test_energy.attack("test_energy");
		test_energy.beRepaired(1);
	}
	cout << "------------------" << std::endl;
}

int	main ( void )
{
	test_death();
	test_energy();
	cout << "TESTS CANONICAL METHODS" << endl;
	ClapTrap no_name;
	ClapTrap name ("name");
	no_name = name;
	ClapTrap copy (name);
	return (0);
}