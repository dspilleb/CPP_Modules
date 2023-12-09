/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:05:13 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 18:51:00 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : my_brain (new Brain())
{
	std::cout << MAGENTA << "Dog : Default constructor called" << NONE << std::endl;
	this->type = "Dog";
	return;
}

Dog::Dog( const Dog & src ) : Animal (src), my_brain (new Brain(*src.my_brain))
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
	delete this->my_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		*(this->my_brain) = *rhs.my_brain;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	(void)i;
	return o;
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