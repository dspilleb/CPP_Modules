/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:10:26 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/20 15:18:58 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie( void )
{
	std::cout << RED + this->name + " destroyed" + NONE << std::endl;
	return;
}

Zombie::Zombie( void )
{
	this->name = "Default";
	return;
}

void Zombie::set_name( std::string given_name )
{
	this->name = given_name;
	return;
}

void Zombie::announce( void )
{
	std::cout << this->name + ": " + "BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}