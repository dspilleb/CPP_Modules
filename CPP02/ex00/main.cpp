/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:06:27 by dspilleb          #+#    #+#             */
/*   Updated: 2024/02/13 11:41:41 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main ( void )
{
	{
		Fixed a;
		Fixed b( a );
		Fixed c;

		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	{
		std::cout << "\n----TEST 2 :" << std::endl;
		Fixed a;

		std::cout << a.getRawBits() << std::endl;
		a.setRawBits(42);
		std::cout << a.getRawBits() << std::endl; // should be 42
	}

	return 0;
}