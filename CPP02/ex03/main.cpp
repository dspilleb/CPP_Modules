/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:06:27 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/04 13:18:03 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int comparaison_operators( void )
{
	Fixed const b( 10 );

	if (!(b > 9) || !(b < 11) || b < 9 || b > 10)
		return(1);
	if (!(b <= 10) || !(b >= 10))
		return (1);
	if (b != 10 || !(b == 10) || !(b != 9) || b == 11)
		return (1);
	return (0);
}

int arithmetics_operators( void )
{
	Fixed const a (5);

	if (a + 2 != 7)
		return (1);
	if (a - 2 != 3)
		return (1);
	if (a / 2 != 2.5f)
		return (1);
	if (a * 2 != 10)
		return (1);
	if ((a * 2) / 2 != 5)
		return (1);
	return (0);
}

void my_tests( void )
{
	if (comparaison_operators())
		std::cout << "ERROR COMPARAISON" << std::endl;
	if (arithmetics_operators())
		std::cout << "ERROR ARITHMETICS" << std::endl;
}

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}