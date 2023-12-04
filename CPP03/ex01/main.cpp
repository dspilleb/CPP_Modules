/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:21:39 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/04 21:25:57 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main ( void )
{
	ScavTrap test ("ScavitoTrapito");
	ClapTrap test2 ("ClapTrapito");

	test.attack("DAN");
	test.takeDamage(2);
	test2.attack("DAN2");
	test2.takeDamage(2);
	test.beRepaired(2);
	test2.beRepaired(2);
	return (0);
}