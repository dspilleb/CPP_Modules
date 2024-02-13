/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:48:54 by dspilleb          #+#    #+#             */
/*   Updated: 2024/02/13 11:31:20 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl ( void )
{
	return;
}

Harl::~Harl ( void )
{
	return ;
}

void Harl::complain( std::string level )
{
	switch (get_level(level))
	{
		case 1:
			debug();
		case 2:
			info();
		case 3:
			warning();
		case 4:
			error();
			break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ] \nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
	return;
}
void Harl::info( void )
{
	std::cout << "[ INFO ] \nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
	return;
}
void Harl::warning( void )
{
	std::cout << "[ WARNING ] \nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
	return;
}
void Harl::error( void )
{
	std::cout << "[ ERROR ] \nThis is unacceptable, I want to speak to the manager now.\n" << std::endl;
	return;
}

int Harl::get_level(const std::string level) const{
	std::string complaints[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = -1;
	while (++i < 4)
		if (level == complaints[i])
			break;
	return (i + 1);
}