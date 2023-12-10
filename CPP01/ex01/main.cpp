/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:11:31 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/10 19:53:18 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int N = 5;

	Zombie* Horde = zombieHorde(N, "zombie_name");
	for (int i = 0; i < N; i++)
		Horde[i].announce();
	delete[] Horde;
	return (0);
}