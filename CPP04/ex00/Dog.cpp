/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:05:13 by dspilleb          #+#    #+#             */
/*   Updated: 2024/03/28 18:15:08 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	std::cout << MAGENTA << "Dog : Default constructor called" << NONE << std::endl;
	this->type = "Dog";
	return;
}

Dog::Dog( const Dog & src ) : Animal (src)
{	
	std::cout << MAGENTA << "Dog: Copy constructor called" << NONE << std::endl;
	this->type = src.type;
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << MAGENTA << "Dog: Destructor called" << NONE << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const
{
	std::cout << "WOUF WOUF" << std::endl;
	return;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */