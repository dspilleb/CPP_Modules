/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:59:23 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 15:59:24 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal() : type ("WrongAnimal")
{
	std::cout << GREEN << "WrongAnimal : Default constructor called" << NONE << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	std::cout << GREEN << "WrongAnimal: Copy constructor called" << NONE << std::endl;
	this->type = src.type;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal: Destructor called" << NONE << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound() const
{
	std::cout << "I'm an WrongAnimal I don't have a sound..." << std::endl;
	return;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& WrongAnimal::getType( void ) const
{
	return (this->type);
}


/* ************************************************************************** */