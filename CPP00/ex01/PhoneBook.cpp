/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:49:38 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 10:17:09 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->number = 0;
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
	int valid = 0;
	int	flag;
	Contact c;
	cout << YELLOW "-------\n| ADD |\n-------\n";
	cout << "Please insert contact information\n" NONE << endl;
	while (valid < 5)
	{
	 	flag = 0;
		std::string buffer;
		cout << info_text[valid] + " : ";
		if (!std::getline(std::cin, buffer))
			return;
		if (buffer.empty())
		{
			cout << RED "No field can be empty" NONE << endl;
			flag = 1;
		}
		else if (valid == 3)
		{
			for (size_t i = 0; i < buffer.length(); i++)
				if (buffer[i] < '0' || buffer[i] > '9')
					flag = 1;
			if (flag)
				cout << RED "Please insert numbers only" NONE << endl;
		}
		if (!flag)
			c.infos[valid++] = buffer;
	}

	if (this->number >= 8)
		this->number = 0;
	this->contacts[this->number] = c;
	this->number++;
}

void	PhoneBook::search(void)
{
	std::string buffer;

	cout << BLUE "----------\n| SEARCH |\n----------\n" NONE;
	if (!this->number)
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

std::string PhoneBook::norm(std::string str)
{
	std::string tmp = str;

	if (!tmp.empty() && tmp.length() > LEN)
	{
		tmp.erase(LEN, tmp.length());
		tmp[LEN - 1] = '.';
	}
	else
		tmp.insert(tmp.end(), (LEN - tmp.length()), ' ');
	tmp.append(1, '|');
	return (tmp);
}

void	PhoneBook::display(void)
{

	std::string header;
	header.append((4 * LEN) + 4, '-');
	cout << BBLACK << header + '\n';
	cout << PhoneBook::norm("index") + PhoneBook::norm("first name") + PhoneBook::norm("last name") + PhoneBook::norm("nickname") + "\n";
	cout << header + NONE + '\n';

	for (int i = 0; i < 8; i++)
	{
		Contact c = this->contacts[i];
		std::ostringstream index;
		index << i;
		cout << PhoneBook::norm(index.str());
		for (int i = 0; i < 3; i++)
		{
			std::string tmp = PhoneBook::norm(c.infos[i]);
			cout << tmp;
		}
		cout << endl;
	}
}
