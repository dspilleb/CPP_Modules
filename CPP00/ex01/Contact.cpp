/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:05:48 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 11:13:28 by dspilleb         ###   ########.fr       */
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

void	Contact::Display(void) const
{
	cout << "✎  first name : " + this->infos[0] + "\n";
	cout << "✎  last name : " + this->infos[1] + "\n";
	cout << "✎  nickname : " + this->infos[2] + "\n";
	cout << "☎  phone number : " + this->infos[3] + "\n";
	cout << "✉  darkest secret : " + this->infos[4] << endl;
	return;
}

std::string Contact::getInfosAtIndex(const int index) const
{
	if (index < 0 || index > 4)
		return("");
	return (this->infos[index]);
}

void Contact::setInfos(const std::string given_infos[5])
{
	for (int i = 0; i < 5; i++)
		this->infos[i] = given_infos[i];
	return;
}
