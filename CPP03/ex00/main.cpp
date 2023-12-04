/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:21:39 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/04 16:12:37 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main ( void )
{
	ClapTrap Optimus_prime ("OPTIMUS_PRIME");
	ClapTrap Megatron ("MEGATRON");

	Optimus_prime.attack("MEGATRON");
	Megatron.takeDamage(9);
	Megatron.attack("OPTIMUS_PRIME");
	Megatron.beRepaired(2);
	Megatron.attack("OPTIMUS_PRIME");
	return (0);
}