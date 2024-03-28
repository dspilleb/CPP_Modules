/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:05:20 by dspilleb          #+#    #+#             */
/*   Updated: 2024/03/28 18:17:57 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : type ("Animal")
{
	std::cout << GREEN << "Animal : Default constructor called" << NONE << std::endl;
}

Animal::Animal( const Animal & src )
{
	std::cout << GREEN << "Animal: Copy constructor called" << NONE << std::endl;
	this->type = src.type;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << GREEN << "Animal: Destructor called" << NONE << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
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

void Animal::makeSound() const
{
	std::cout << "I'm an animal I don't have a sound..." << std::endl;
	return;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Animal::getType( void ) const
{
	return (this->type);
}


/* ************************************************************************** */