/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:21:39 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/07 12:06:50 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main ( void )
{
	ScavTrap test ("ScavitoTrapito");
	ClapTrap test2 ("ClapTrapito");

	test.attack("ClapTrapito");
	test2.takeDamage(20);
	test2.attack("ScavitoTrapito");
	test2.takeDamage(2);
	test.beRepaired(2);
	test2.beRepaired(2);
	test.guardGate();
	test.takeDamage(1);
	ScavTrap test3 = test;
	test3.beRepaired(1);
	test.beRepaired(1);
	return (0);
}