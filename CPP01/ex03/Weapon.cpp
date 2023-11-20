/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:20:04 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/20 16:23:47 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string set_type )
{
	this->type = set_type;
	return;
}

Weapon::~Weapon( void )
{
	return;
}

const std::string& Weapon::getType( void )
{
	std::string& weapon_reference = this->type;
	return (weapon_reference);
}

void Weapon::setType( std::string new_type )
{
	this->type = new_type;
	return;
}