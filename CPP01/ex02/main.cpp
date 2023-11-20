/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:25:09 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/20 15:38:22 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = std::string("HI THIS IS BRAIN");
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << &str << "\n";
	std::cout << stringPTR << "\n";
	std::cout << &stringREF << "\n";


	std::cout << str << "\n";
	std::cout << *stringPTR << "\n";
	std::cout << stringREF << std::endl;
	return (0);
}