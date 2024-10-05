/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:27:09 by dspilleb          #+#    #+#             */
/*   Updated: 2024/10/05 11:57:40 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : 
_name("Default"), 
_is_signed(false), 
_sign_required_grade(150), 
_exec_required_grade(150)
{
	return;
}

Form::Form( const Form & src ) : 
_name(src._name), 
_is_signed(src._is_signed),  
_sign_required_grade(src._sign_required_grade), 
_exec_required_grade(src._exec_required_grade)
{
	return;
}

Form::Form(std::string set_name, int set_sign_required_grade, int set_exec_required_grade) : 
_name(set_name), 
_is_signed(false), 
_sign_required_grade(set_sign_required_grade), 
_exec_required_grade(set_exec_required_grade)
{
	if ( _exec_required_grade > 150 || _sign_required_grade > 150)
		throw GradeTooLowException();
	else if ( _exec_required_grade < 1 || _sign_required_grade < 1)
		throw GradeTooHighException();
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		_is_signed = rhs._is_signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << i.GetName() << (i.GetSignedState() ? ", is signed" : ", is not signed") ;
	o << ", required grade to sign : " << i.GetSignRequiredGrade();
	o << ", required grade to execute : " << i.GetExecRequiredGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(const Bureaucrat& b)
{
	if (b.GetGrade() <= _sign_required_grade)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string	&Form::GetName ( void ) const
{
	return (_name);
}

bool		Form::GetSignedState ( void ) const
{
	return (_is_signed);
}

int			Form::GetSignRequiredGrade ( void ) const
{
	return (_sign_required_grade);
}

int			Form::GetExecRequiredGrade ( void ) const
{
	return (_exec_required_grade);
}


/*
** --------------------------------- Exceptions ----------------------------------
*/

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too High !");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}


/* ************************************************************************** */