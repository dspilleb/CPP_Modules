/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:06:31 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/02 15:15:44 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ( void )
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed & ref)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = ref.getRawBits();
	return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits (int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
	return;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}