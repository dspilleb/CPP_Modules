/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:12:00 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/20 15:22:01 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string given_name )
{
	Zombie* Horde = NULL;
	if (N >= 0)
	{
		Horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			Horde[i].set_name(given_name);
	}
	return (Horde);
}