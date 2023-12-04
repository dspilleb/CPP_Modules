/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:06:31 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/04 11:32:50 by dspilleb         ###   ########.fr       */
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

Fixed::Fixed(const int init_val)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = init_val << point_bit_position;
	return ;
}

Fixed::Fixed(const float init_val)
{
	std::cout << "float constructor called" << std::endl;
	this->value = roundf(init_val * (1 << point_bit_position));
	return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits (int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
	return;
}

float Fixed::toFloat ( void ) const
{
	return ((float)this->getRawBits() / (1 << point_bit_position));
}

int Fixed::toInt ( void ) const
{
	return (this->getRawBits() >> point_bit_position);
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}


int Fixed::get_point_bit_position ( void ) const
{
	return (this->point_bit_position);
}

std::ostream& operator<<(std::ostream &os, Fixed const &ref)
{
	os << ((float)ref.getRawBits() / (1 << ref.get_point_bit_position()));
	return (os);
}