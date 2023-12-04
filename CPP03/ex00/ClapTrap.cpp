/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:49:56 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/04 15:05:00 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string given_name)
{
	std::cout << GREEN << "Default constructor called" << NONE << std::endl;
	this->name = given_name;
	this->energy_points = 10;
	this->hit_points = 10;
	this->attack_damage = 0;
	return;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << GREEN << "Copy constructor called" << NONE << std::endl;
	this->name = src.attack_damage;
	this->energy_points = src.energy_points;
	this->hit_points = src.hit_points;
	this->attack_damage = src.attack_damage;
	return;
}


ClapTrap::~ClapTrap()
{
	std::cout << RED << "Destructor called" << NONE << std::endl;
	return;
}


ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << GREEN << "Copy assignment operator called" << NONE << std::endl;
	if ( this != &rhs )
	{
		this->name = rhs.attack_damage;
		this->energy_points = rhs.energy_points;
		this->hit_points = rhs.hit_points;
		this->attack_damage = rhs.attack_damage;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
{
	return o;
}


void ClapTrap::attack(const std::string& target)
{
	return;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	return;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	return;
}