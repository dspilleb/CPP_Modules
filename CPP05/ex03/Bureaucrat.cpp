/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:27:16 by dspilleb          #+#    #+#             */
/*   Updated: 2024/03/02 18:54:16 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string setname, int setgrade): name(setname), grade(setgrade) 
{
	if (this->grade > 150)
		throw GradeTooLowException();
	else if (this->grade < 1)
		throw GradeTooHighException();
	return;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : name(src.name), grade(src.grade) 
{
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
		this->grade = rhs.GetGrade();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.GetName() << ", bureaucrat grade " << i.GetGrade() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::increment( void )
{
	if (this->grade - 1 > 150)
		throw GradeTooLowException();
	else if (this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade--;
	return;
}

void Bureaucrat::decrement( void )
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	else if (this->grade + 1 < 1)
		throw GradeTooHighException();
	this->grade++;
	return;
}

void Bureaucrat::signForm( AForm& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.GetName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn’t sign " << f.GetName() << " because " << e.what() << std::endl;
	}
	
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.GetName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn’t execute " << form.GetName() << " because " << e.what() << std::endl;
	}
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::GetName( void ) const
{
	return (this->name);
}

int Bureaucrat::GetGrade( void ) const
{
	return (this->grade);
}

/*
** --------------------------------- Exceptions ----------------------------------
*/

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High ! (above 1)");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low ! (under 150)");
}


/* ************************************************************************** */