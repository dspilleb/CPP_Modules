/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:48:54 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/23 22:39:19 by dspilleb         ###   ########.fr       */
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

	void (Harl::*p) ( void );
	return;
}

void Harl::debug( void )
{
	std::cout << "[ debug ] \nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return;
}
void Harl::info( void )
{
	std::cout << "[ INFO ] \n I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return;
}
void Harl::warning( void )
{
	std::cout << "[ WARNING ] \n I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
	return;
}
void Harl::error( void )
{
	std::cout << "[ ERROR ] \n This is unacceptable, I want to speak to the manager now" << std::endl;
	return;
}