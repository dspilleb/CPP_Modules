/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:20:04 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/20 17:34:42 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon ( void )
{
	this->type = "Default";
	return;
}

Weapon::~Weapon( void )
{
	return;
}

Weapon::Weapon( std::string set_type )
{
	this->type = set_type;
	return;
}

const std::string& Weapon::getType( void )
{
	return (this->type);
}

void Weapon::setType( std::string new_type )
{
	this->type = new_type;
	return;
}