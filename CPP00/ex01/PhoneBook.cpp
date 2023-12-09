/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:49:38 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 11:12:41 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : number_contacts (0)
{
	this->info_text[0] = "first name";
	this->info_text[1] = "last name";
	this->info_text[2] = "nickname";
	this->info_text[3] = "☎  number";
	this->info_text[4] = "✉  darkest secret";
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::add(void)
{
	int info_nmb = 0;
	int	valid;
	Contact c;
	cout << YELLOW "-------\n| ADD |\n-------\n";
	cout << "Please insert contact information\n" NONE << endl;
	std::string infos[5];
	while (info_nmb < 5)
	{
	 	valid = 1;
		std::string buffer;
		cout << info_text[info_nmb] + " : ";
		if (!std::getline(std::cin, buffer))
			return;
		if (buffer.empty())
		{
			cout << RED "No field can be empty" NONE << endl;
			valid = 0;
		}
		else if (info_nmb == 3)
		{
			for (size_t i = 0; i < buffer.length(); i++)
				if (buffer[i] < '0' || buffer[i] > '9')
					valid = 0;
			if (!valid)
				cout << RED "Please insert numbers only" NONE << endl;
		}
		if (valid)
			infos[info_nmb++] = buffer;
	}
	c.setInfos(infos);
	if (this->number_contacts >= 8)
		this->number_contacts = 0;
	this->contacts[this->number_contacts] = c;
	this->number_contacts++;
}

void	PhoneBook::search(void) const
{
	std::string buffer;

	cout << BLUE "----------\n| SEARCH |\n----------\n" NONE;
	if (!this->number_contacts)
	{
		cout << BLUE "You have no contacts" NONE << endl;
		return ;
	}
	this->display();
	cout << BLUE "Please specify a contact :\n>> " NONE;
	while (std::getline(std::cin, buffer))
	{
		if (!buffer.empty() && buffer.length() == 1 && buffer >= "0" && buffer < "8")
		{
			this->contacts[buffer[0] - '0'].Display();
			return;
		}
		else
			cout << RED "You must enter a number referring to the index of a contact\n" BLUE ">> " NONE << std::flush;
	}
}

std::string PhoneBook::norm(const std::string str) const
{
	std::string normed_str = str;

	if (!normed_str.empty() && normed_str.length() > LEN)
	{
		normed_str.erase(LEN, normed_str.length());
		normed_str[LEN - 1] = '.';
	}
	else
		normed_str.insert(normed_str.end(), (LEN - normed_str.length()), ' ');
	normed_str.append(1, '|');
	return (normed_str);
}

void	PhoneBook::display(void) const
{

	std::string header;
	header.append((COLS * LEN) + COLS, '-');
	cout << BBLACK << header + '\n';
	cout << PhoneBook::norm("index") + PhoneBook::norm("first name") + PhoneBook::norm("last name") + PhoneBook::norm("nickname") + "\n";
	cout << header + NONE + '\n';

	for (int i = 0; i < 8; i++)
	{
		Contact c = this->contacts[i];
		std::ostringstream contact_index;
		contact_index << i;
		cout << PhoneBook::norm(contact_index.str());
		for (int i = 0; i < 3; i++)
		{
			std::string tmp = PhoneBook::norm(c.getInfosAtIndex(i));
			cout << tmp;
		}
		cout << endl;
	}
}
