/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:46:49 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/08 09:41:52 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <stdlib.h>
# include <string>
# include <iostream>
# include <sstream>


# define GREEN "\033[1;32m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define BWHITE "\033[1;37m";
# define BBLACK "\033[1;30m";
# define MAGENTA "\033[1;35m"
# define LEN 10

class PhoneBook{
	private:
		int number;
		std::string info_text[5];
		Contact contacts[8];
	public:
		std::string norm( std::string );
		void add( void );
		void search( void );
		void display( void );
		PhoneBook( void );
		~PhoneBook( void );
};

#endif