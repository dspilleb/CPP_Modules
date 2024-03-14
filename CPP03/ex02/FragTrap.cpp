/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:50:20 by dspilleb          #+#    #+#             */
/*   Updated: 2024/03/14 15:14:27 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	std::cout << GREEN "FragTrap: Default constructor called" NONE << std::endl;
	this->name = "Default";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	return;
}

FragTrap::FragTrap(std::string given_name)
{
	std::cout << GREEN "FragTrap: Default constructor called" NONE << std::endl;
	this->name = given_name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	return;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	std::cout << GREEN << "FragTrap: Copy constructor called" << NONE << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << RED "FragTrap: Destructor called" NONE << std::endl;
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << GREEN << "FragTrap: Copy assignment operator called" << NONE << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hit_points = rhs.hit_points;
		this->energy_points = rhs.energy_points;
		this->attack_damage = rhs.attack_damage;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	(void) i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::attack(const std::string& target)
{
	if (this->hit_points < 1)
		std::cout << BBLACK << this->name << ": " ORANGE "Dead FragTrap cannot make action" NONE << std::endl;
	else if (this->energy_points < 1)
		std::cout << BBLACK << this->name << ": " YELLOW"FragTrap needs energy to make an action" NONE << std::endl;
	else
	{
		std::cout << BBLACK  "FragTrap " << this->name << NONE ": attacks " BLUE << target << RED " causing " << this->attack_damage << " points of damage!" NONE << std::endl;
		this->energy_points--;
	}
	return;
}


void FragTrap::highFivesGuys(void)
{
	std::cout << BBLACK "FragTrap " << this->name << ": " YELLOW "wants a High Five" NONE << std::endl;
	return;
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */