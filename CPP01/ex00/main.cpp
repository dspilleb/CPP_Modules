/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:40 by dspilleb          #+#    #+#             */
/*   Updated: 2024/02/16 11:23:22 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie Zombie1 = Zombie("Zombie1");
	Zombie1.announce();

	randomChump("randomChump");

	Zombie* Zombie2 = newZombie("Zombie2");
	if (Zombie2)
	{
		Zombie2->announce();
		delete Zombie2;
	}

	return (0);
}