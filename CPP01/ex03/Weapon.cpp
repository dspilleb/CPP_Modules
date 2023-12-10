/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:20:04 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/10 19:57:07 by dspilleb         ###   ########.fr       */
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

Weapon::Weapon( const std::string set_type )
{
	this->type = set_type;
	return;
}

const std::string& Weapon::getType( void ) const
{
	return (this->type);
}

void Weapon::setType( const std::string new_type )
{
	this->type = new_type;
	return;
}