/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:54 by dspilleb          #+#    #+#             */
/*   Updated: 2024/10/05 18:49:57 by dspilleb         ###   ########.fr       */
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
		std::cout << Y << "\n*-*-*-*-*-* Success Pardon test *-*-*-*-*-*\n" << C;
		PresidentialPardonForm Pardon = PresidentialPardonForm("Dan");
		Bureaucrat Donald = Bureaucrat("Joe Biden", 4);
		Donald.signForm(Pardon);
		Donald.executeForm(Pardon);
	}
	{
		std::cout << Y << "\n*-*-*-*-*-* Fail Pardon test *-*-*-*-*-*\n" << C;
		PresidentialPardonForm Pardon = PresidentialPardonForm("Dan");
		Bureaucrat Donald = Bureaucrat("Joe Biden", 6);
		Donald.signForm(Pardon);
		Donald.executeForm(Pardon);
	}
	{
		std::cout << Y << "\n*-*-*-*-*-* Sucess Robotomy test *-*-*-*-*-*\n" << C;
		RobotomyRequestForm Robotomty = RobotomyRequestForm("42");
		Bureaucrat Member = Bureaucrat("19 member", 1);
		Member.signForm(Robotomty);
		Member.executeForm(Robotomty);
	}
	{
		std::cout << Y << "\n*-*-*-*-*-* Sucess Shrubbery test *-*-*-*-*-*\n" << C;
		ShrubberyCreationForm creation = ShrubberyCreationForm("42");
		Bureaucrat Member = Bureaucrat("19 member", 1);
		Member.signForm(creation);
		Member.executeForm(creation);
	}
	{
		std::cout << Y << "\n*-*-*-*-*-* Form not signed test *-*-*-*-*-*\n" << C;
		ShrubberyCreationForm creation = ShrubberyCreationForm("42");
		Bureaucrat Member = Bureaucrat("19 member", 1);
		Member.executeForm(creation);
	}

	return 0;
}