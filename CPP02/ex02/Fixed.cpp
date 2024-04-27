/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:06:31 by dspilleb          #+#    #+#             */
/*   Updated: 2024/03/01 13:52:23 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ( void ) : value (0)
{
	// std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed & ref)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->value = ref.getRawBits();
	return ;
}

Fixed::Fixed(const int init_val)
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = init_val << point_bit_position;
	return ;
}

Fixed::Fixed(const float init_val)
{
	// std::cout << "Float constructor called" << std::endl;
	this->value = roundf(init_val * (1 << point_bit_position));
	return ;
}

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
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

bool Fixed::operator>(Fixed const &second) const
{
	return (this->getRawBits() > second.getRawBits());
}

bool Fixed::operator<(Fixed const &second) const
{
	return (this->getRawBits() < second.getRawBits());
}

bool Fixed::operator>=(Fixed const &second) const
{
	return (this->getRawBits() >= second.getRawBits());
}

bool Fixed::operator<=(Fixed const &second) const
{
	return (this->getRawBits() <= second.getRawBits());
}

bool Fixed::operator==(Fixed const &second) const
{
	return (this->getRawBits() == second.getRawBits());
}

bool Fixed::operator!=(Fixed const &second) const
{
	return (this->getRawBits() != second.getRawBits());
}

Fixed Fixed::operator+(Fixed const &second) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + second.getRawBits());
	return (result);
}

Fixed Fixed::operator-(Fixed const &second) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - second.getRawBits());
	return (result);
}

Fixed Fixed::operator/(Fixed const &second) const
{
	float val = this->toFloat() / second.toFloat();
	Fixed result (val);
	return (result);
}

Fixed Fixed::operator*(Fixed const &second) const
{
	float val = this->toFloat() * second.toFloat();
	Fixed result (val);
	return (result);
}

Fixed& Fixed::operator++( void )
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed old = *this;
	this->value++;
	return (old);
}

Fixed& Fixed::operator--( void )
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed old = *this;
	this->value--;
	return (old);
}

Fixed Fixed::max(Fixed const &first, Fixed const &second)
{
	if (first >= second)
		return (Fixed(first));
	else
		return(Fixed(second));
}

Fixed& Fixed::max(Fixed &first, Fixed &second)
{
	if (first >= second)
		return (first);
	else
		return(second);
}

Fixed Fixed::min(Fixed const &first, Fixed const &second)
{
	if (first <= second)
		return (Fixed(first));
	else
		return(Fixed(second));
}

Fixed& Fixed::min(Fixed &first, Fixed &second)
{
	if (first <= second)
		return (first);
	else
		return(second);
}