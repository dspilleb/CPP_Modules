/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:27:16 by dspilleb          #+#    #+#             */
/*   Updated: 2024/10/05 11:57:23 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string setname, int setgrade): _name(setname), _grade(setgrade) 
{
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
	return;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name), _grade(src._grade) 
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
		_grade = rhs.GetGrade();
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
	if (_grade - 1 > 150)
		throw GradeTooLowException();
	else if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
	return;
}

void Bureaucrat::decrement( void )
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else if (_grade + 1 < 1)
		throw GradeTooHighException();
	_grade++;
	return;
}

void Bureaucrat::signForm( Form& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.GetName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn’t sign " << f.GetName() << " because " << e.what() << std::endl;
	}
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::GetName( void ) const
{
	return (_name);
}

int Bureaucrat::GetGrade( void ) const
{
	return (_grade);
}

/*
** --------------------------------- Exceptions ----------------------------------
*/

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too High !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low !");
}


/* ************************************************************************** */