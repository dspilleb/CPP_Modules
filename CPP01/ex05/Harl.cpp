/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:48:54 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/10 20:10:41 by dspilleb         ###   ########.fr       */
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
	int has_complained = 0;
	std::string complaints[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func[]) ( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (size_t i = 0; i < complaints->length(); i++)
	{
		if (level == complaints[i])
		{
			(this->*func[i])();
			has_complained = 1;
		}
	}
	if (!has_complained)
		std::cout << "[ CONFUSION ] \nWhat do you want ? Move on, I have things to do..." << std::endl;
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
	std::cout << "[ ERROR ] \nThis is unacceptable, I want to speak to the manager now" << std::endl;
	return;
}