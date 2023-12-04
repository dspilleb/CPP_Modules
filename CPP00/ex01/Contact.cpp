/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:05:48 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/08 09:34:41 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::Display(void)
{
	std::cout << "✎  first name : " + this->infos[0] + "\n";
	std::cout << "✎  last name : " + this->infos[1] + "\n";
	std::cout << "✎  nickname : " + this->infos[2] + "\n";
	std::cout << "☎  phone number : " + this->infos[3] + "\n";
	std::cout << "✉  darkest secret : " + this->infos[4] << std::endl;
	return;
}