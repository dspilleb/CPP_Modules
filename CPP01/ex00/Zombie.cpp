/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:09:37 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/20 13:41:17 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	return;
}

Zombie::~Zombie( void )
{
	std::cout << RED + this->name + " Has been destroyed" + NONE << std::endl;
	return;
}

Zombie::Zombie(std::string given_name)
{
	this->name = given_name;
}

void Zombie::announce( void )
{
	if (!this->name.empty())
		std::cout << this->name + ": " + "BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}