/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:49:38 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/08 09:56:45 by dspilleb         ###   ########.fr       */
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
	std::cout << YELLOW "-------\n| ADD |\n-------\n";
	std::cout << "Please insert contact information\n" NONE << std::endl;
	while (valid < 5)
	{
	 	flag = 0;
		std::string buffer;
		std::cout << info_text[valid] + " : ";
		if (!std::getline(std::cin, buffer))
			return;
		if (buffer.empty())
		{
			std::cout << RED "No field can be empty" NONE << std::endl;
			flag = 1;
		}
		else if (valid == 3)
		{
			for (size_t i = 0; i < buffer.length(); i++)
				if (buffer[i] < '0' || buffer[i] > '9')
					flag = 1;
			if (flag)
				std::cout << RED "Please insert numbers only" NONE << std::endl;
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

	std::cout << BLUE "----------\n| SEARCH |\n----------\n" NONE;
	if (!this->number)
	{
		std::cout << BLUE "You have no contacts" NONE << std::endl;
		return ;
	}
	this->display();
	std::cout << BLUE "Please specify a contact :\n>> " NONE;
	while (std::getline(std::cin, buffer))
	{
		if (!buffer.empty() && buffer.length() == 1 && buffer >= "0" && buffer < "8")
		{
			this->contacts[buffer[0] - '0'].Display();
			return;
		}
		else
			std::cout << RED "You must enter a number referring to the index of a contact\n" BLUE ">> " NONE << std::flush;
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
	std::cout << BBLACK header + '\n';
	std::cout << PhoneBook::norm("index") + PhoneBook::norm("first name") + PhoneBook::norm("last name") + PhoneBook::norm("nickname") + "\n";
	std::cout << header + NONE + '\n';

	for (int i = 0; i < 8; i++)
	{
		Contact c = this->contacts[i];
		std::ostringstream index;
		index << i;
		std::cout << PhoneBook::norm(index.str());
		for (int i = 0; i < 3; i++)
		{
			std::string tmp = PhoneBook::norm(c.infos[i]);
			std::cout << tmp;
		}
		std::cout << "\n" << std::flush;
	}
}
