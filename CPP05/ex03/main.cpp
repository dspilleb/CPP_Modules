/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:54 by dspilleb          #+#    #+#             */
/*   Updated: 2024/08/07 14:57:03 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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
		Member.executeForm(Robotomty);
		Member.executeForm(Robotomty);
		Member.executeForm(Robotomty);
	}
	{
		std::cout << "\n*-*-*-*-*-* Robotomy test *-*-*-*-*-*\n";
		ShrubberyCreationForm creation = ShrubberyCreationForm("42");
		Bureaucrat Member = Bureaucrat("19 member", 1);
		Member.executeForm(creation);
	}
	{
		std::cout << "\n*-*-*-*-*-* INTERN test *-*-*-*-*-*\n";
		Bureaucrat Elon = Bureaucrat("Elon Musk", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) rrf->execute(Elon);
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf) rrf->execute(Elon);
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf) rrf->execute(Elon);
	}

	return 0;
}