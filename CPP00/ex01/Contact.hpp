/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:05:45 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 10:15:20 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# define GREEN "\033[1;32m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define BWHITE "\033[1;37m"
# define BBLACK "\033[1;30m"
# define MAGENTA "\033[1;35m"

using std::cout;
using std::endl;

class Contact{

public:
	std::string infos[5];
	void Display(void) const;
	Contact(void);
	~Contact(void);
};

#endif