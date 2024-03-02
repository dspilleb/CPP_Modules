/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:27:09 by dspilleb          #+#    #+#             */
/*   Updated: 2024/03/02 16:16:43 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : name("Default"), is_signed(false), sign_required_grade(150), exec_required_grade(150)
{
	return;
}

Form::Form( const Form & src ) : name(src.name), is_signed(src.is_signed), 
sign_required_grade(src.sign_required_grade), exec_required_grade(src.exec_required_grade)
{
	return;
}

Form::Form(std::string set_name, bool set_signed_state, int set_sign_required_grade, int set_exec_required_grade) : name(set_name), is_signed(set_signed_state),
sign_required_grade(set_sign_required_grade), exec_required_grade(set_exec_required_grade)
{
	if ( this->exec_required_grade > 150 || this->sign_required_grade > 150)
		throw GradeTooLowException();
	else if ( this->exec_required_grade < 1 || this->sign_required_grade < 1)
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
		this->is_signed = rhs.is_signed;
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
	if (b.GetGrade() <= this->sign_required_grade)
		this->is_signed = true;
	else
		throw Form::GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Form::GetName ( void ) const
{
	return (this->name);
}

bool		Form::GetSignedState ( void ) const
{
	return (this->is_signed);
}

int			Form::GetSignRequiredGrade ( void ) const
{
	return (this->sign_required_grade);
}

int			Form::GetExecRequiredGrade ( void ) const
{
	return (this->exec_required_grade);
}

/*
** --------------------------------- Exceptions ----------------------------------
*/

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too High ! (above 1)");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low ! (under 150)");
}

/* ************************************************************************** */