/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:05:48 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 10:18:14 by dspilleb         ###   ########.fr       */
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