/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:26:13 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/22 16:54:45 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
HumanA::HumanA(std::string set_name, Weapon& set_weapon) :weapon(set_weapon)
{
	this->name = set_name;
	return ;
}

HumanA::~HumanA()
{
	return;
}

void HumanA::attack( void )
{
	std::cout << this->name + " attacks with their " << this->weapon.getType() << std::endl;
	return ;
}