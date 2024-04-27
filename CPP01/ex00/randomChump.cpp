/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:13:04 by dspilleb          #+#    #+#             */
/*   Updated: 2024/02/16 11:21:20 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 	"Zombie.hpp"

void randomChump( std::string given_name )
{
	Zombie(given_name).announce();
	return;
}