/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:49:56 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/04 16:31:07 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap( void ) : name("Default"), hit_points ( 10 ), energy_points ( 10 ), attack_damage ( 0 )
{
	std::cout << GREEN << "Default constructor called" << NONE << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string given_name) : name(given_name), hit_points ( 10 ), energy_points ( 10 ), attack_damage ( 0 )
{
	std::cout << GREEN << "Name constructor called" << NONE << std::endl;
	return;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << GREEN << "Copy constructor called" << NONE << std::endl;
	this->name = src.name;
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
	(void) i;
	return o;
}


void ClapTrap::attack(const std::string& target)
{
	if (this->hit_points < 1)
		std::cout << BBLACK << this->name << ": " << ORANGE << "Dead ClapTrap cannot make action" << NONE << std::endl;
	else if (this->energy_points < 1)
		std::cout << BBLACK << this->name << ": " << YELLOW << "ClapTrap needs energy to make an action" << NONE << std::endl;
	else
	{
		std::cout << BBLACK << this->name << NONE ": attacks " << BLUE << target << RED <<" causing " << this->attack_damage << " points of damage!" << NONE << std::endl;
		this->energy_points--;
	}
	return;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	this->hit_points -= amount;
	return;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points < 1)
		std::cout << BBLACK << this->name << ": " << ORANGE << "Dead ClapTrap cannot make action" << NONE << std::endl;
	else if (this->energy_points < 1)
		std::cout << BBLACK << this->name << ": " << YELLOW << "ClapTrap needs energy to make an action" << NONE << std::endl;
	else
	{
		this->energy_points--;
		this->hit_points += amount;
		std::cout << MAGENTA << this->name << ": " << "repaired " << amount << " hit points, it has now " << this->hit_points << " hit points" << NONE << std::endl;
	}
	return;
}