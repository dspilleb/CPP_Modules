/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:54 by dspilleb          #+#    #+#             */
/*   Updated: 2024/10/05 19:00:39 by dspilleb         ###   ########.fr       */
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

	{
		std::cout << Y << "\n*-*-*-*-*-* INTERN test *-*-*-*-*-*\n" << C;
		Bureaucrat Elon = Bureaucrat("Elon Musk", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) {	
			Elon.signForm(*rrf);
			Elon.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf) {	
			Elon.signForm(*rrf);
			Elon.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf) {	
			Elon.signForm(*rrf);
			Elon.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;

		//doesn't exist 
		rrf = someRandomIntern.makeForm("rfsdfs", "Bender");
		if (rrf){
			Elon.signForm(*rrf);
			Elon.executeForm(*rrf);
			delete rrf;
		}
	}

	return 0;
}