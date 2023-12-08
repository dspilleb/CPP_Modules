/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:47:52 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/08 11:32:17 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << GREEN "ScavTrap: Default constructor called" NONE << std::endl;
	this->name = "Default";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	return;
}

ScavTrap::ScavTrap(std::string given_name)
{
	std::cout << GREEN "ScavTrap: Default constructor called" NONE << std::endl;
	this->name = given_name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	return;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED "ScavTrap: Destructor called" NONE << std::endl;
	return;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hit_points < 1)
		std::cout << BBLACK << this->name << ": " ORANGE "Dead ScavTrap cannot make action" NONE << std::endl;
	else if (this->energy_points < 1)
		std::cout << BBLACK << this->name << ": " YELLOW"ScavTrap needs energy to make an action" NONE << std::endl;
	else
	{
		std::cout << BBLACK  "ScavTrap " << this->name << NONE ": attacks " BLUE << target << RED " causing " << this->attack_damage << " points of damage!" NONE << std::endl;
		this->energy_points--;
	}
	return;
}

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
{
	(void)i;
	return o;
}

void ScavTrap::guardGate()
{
	std::cout << BBLACK "ScavTrap " << this->name << ": " YELLOW "GUARDGATE MODE ACTIVATED" NONE << std::endl;
}


ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap(src)
{
	std::cout << GREEN << "ScavTrap: Copy constructor called" << NONE << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
}

ScavTrap &		ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << GREEN << "ScavTrap: Copy assignment operator called" << NONE << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hit_points = rhs.hit_points;
		this->energy_points = rhs.energy_points;
		this->attack_damage = rhs.attack_damage;
	}
	return *this;
}