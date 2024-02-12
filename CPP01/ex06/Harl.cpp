/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:48:54 by dspilleb          #+#    #+#             */
/*   Updated: 2024/02/12 12:24:12 by dspilleb         ###   ########.fr       */
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
			info();
			warning();
			error();
			break;
		case 2:
			info();
			warning();
			error();
			break;
		case 3:
			warning();
			error();
			break;
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
	std::cout << "[ DEBUG ] \nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return;
}
void Harl::info( void )
{
	std::cout << "[ INFO ] \nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return;
}
void Harl::warning( void )
{
	std::cout << "[ WARNING ] \nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
	return;
}
void Harl::error( void )
{
	std::cout << "[ ERROR ] \nThis is unacceptable, I want to speak to the manager now." << std::endl;
	return;
}

int Harl::get_level(const std::string level) const{
	if (level == "DEBUG")
		return (1);
	else if (level == "INFO")
		return (2);
	else if (level == "WARNING")
		return (3);
	else if (level == "ERROR")
		return (4);
	return (0);
}