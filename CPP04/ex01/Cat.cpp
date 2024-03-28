/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:05:16 by dspilleb          #+#    #+#             */
/*   Updated: 2024/03/28 19:26:17 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : my_brain (new Brain())
{
	std::cout << BLUE << "Cat : Default constructor called" << NONE << std::endl;
	this->type = "Cat";
	return;
}

Cat::Cat( const Cat & src ) : Animal (src), my_brain (new Brain(*src.my_brain))
{
	std::cout << BLUE << "Cat: Copy constructor called" << NONE << std::endl;
	this->type = src.type;
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << BLUE << "Cat: Destructor called" << NONE << std::endl;
	delete this->my_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		*(this->my_brain) = *rhs.my_brain;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
	return;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain *Cat::getbrain( void )
{
	return (this->my_brain);
}


/* ************************************************************************** */