/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:54 by dspilleb          #+#    #+#             */
/*   Updated: 2024/10/05 12:29:31 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	{
		std::cout << "\n*-*-*-*-*-* Sucess Pardon test *-*-*-*-*-*\n";
		PresidentialPardonForm Pardon = PresidentialPardonForm("Dan");
		Bureaucrat Donald = Bureaucrat("Joe Biden", 4);
		std::cout << Pardon << std::endl;
		Donald.executeForm(Pardon);
	}
	{
		std::cout << "\n*-*-*-*-*-* Fail Pardon test *-*-*-*-*-*\n";
		PresidentialPardonForm Pardon = PresidentialPardonForm("Dan");
		Bureaucrat Donald = Bureaucrat("Joe Biden", 6);
		std::cout << Pardon << std::endl;
		Donald.executeForm(Pardon);
	}
	{
		std::cout << "\n*-*-*-*-*-* Robotomy test *-*-*-*-*-*\n";
		RobotomyRequestForm Robotomty = RobotomyRequestForm("42");
		Bureaucrat Member = Bureaucrat("19 member", 1);
		Member.executeForm(Robotomty);
	}
	{
		std::cout << "\n*-*-*-*-*-* Robotomy test *-*-*-*-*-*\n";
		ShrubberyCreationForm creation = ShrubberyCreationForm("42");
		Bureaucrat Member = Bureaucrat("19 member", 1);
		Member.executeForm(creation);
	}

	return 0;
}