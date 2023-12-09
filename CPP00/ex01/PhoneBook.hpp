/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:46:49 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 11:12:30 by dspilleb         ###   ########.fr       */
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
# define COLS 4

class PhoneBook{
	private:
		int number_contacts;
		std::string info_text[5];
		Contact contacts[8];
		std::string norm( const std::string ) const;
	public:
		void add( void );
		void search( void ) const;
		void display( void ) const;
		PhoneBook( void );
		~PhoneBook( void );
};

#endif