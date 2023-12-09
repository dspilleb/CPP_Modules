/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:21:39 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 14:08:33 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

using std::cout;
using std::endl;


void test_death( void )
{
	cout << "----TEST DEATH----" << std::endl;
	{
		ScavTrap test_death ("test_death");

		test_death.takeDamage(10);
		test_death.attack("42");
		test_death.takeDamage(90);
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
		ScavTrap test_energy ("test_energy");

		for (int i = 0; i < 51; i++)
			test_energy.attack("test_energy");
		test_energy.beRepaired(1);
	}
	cout << "------------------" << std::endl;
}

void test_special_ability( void )
{
	cout << "----TEST ABILITY----" << std::endl;
	{
		ScavTrap test_ability ("test_ability");

		test_ability.guardGate();
	}
	cout << "------------------" << std::endl;
}

int	main ( void )
{
	test_death();
	test_energy();
	test_special_ability();
	return (0);
}