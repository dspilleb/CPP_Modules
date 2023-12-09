/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:25:30 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 10:15:50 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>

int main()
{
	std::string buffer;
	PhoneBook tel;

	cout << BLUE "You have 3 commands : ADD | SEARCH | EXIT" NONE << endl;
	while (1)
	{
		cout << ">> " << std::flush;
		if (!std::getline(std::cin, buffer) || buffer.compare("EXIT") == 0)
		{
			cout << BLUE "\n-------------\n| You Exited |\n-------------" NONE << endl;
			return (0);
		}
		if (buffer.compare("ADD") == 0)
			tel.add();
		if (buffer.compare("SEARCH") == 0)
			tel.search();
	}
	return (0);
}