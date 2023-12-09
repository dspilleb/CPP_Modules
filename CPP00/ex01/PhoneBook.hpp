/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:46:49 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 10:13:42 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <stdlib.h>
# include <string>
# include <iostream>
# include <sstream>

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