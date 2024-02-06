/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:48:52 by dspilleb          #+#    #+#             */
/*   Updated: 2024/02/06 20:58:57 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Veuillez introduire un niveau de plainte de HARL :\n'DEBUG' | 'INFO' | 'WARNING' | 'ERROR'" << std::endl;
		return (1);
	}
	Harl my_harl;
	my_harl.complain(av[1]);
	return (0);
}