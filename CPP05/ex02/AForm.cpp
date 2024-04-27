/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:27:09 by dspilleb          #+#    #+#             */
/*   Updated: 2024/03/02 19:08:54 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : name("Default"), is_signed(false), sign_required_grade(150), exec_required_grade(150)
{
	return;
}

AForm::AForm( const AForm & src ) : name(src.name), is_signed(src.is_signed), 
sign_required_grade(src.sign_required_grade), exec_required_grade(src.exec_required_grade)
{
	return;
}

AForm::AForm(std::string set_name, bool set_signed_state, int set_sign_required_grade, int set_exec_required_grade) : name(set_name), is_signed(set_signed_state),
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

AForm::~AForm()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->is_signed = rhs.is_signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << i.GetName() << (i.GetSignedState() ? ", is signed" : ", is not signed") ;
	o << ", required grade to sign : " << i.GetSignRequiredGrade();
	o << ", required grade to execute : " << i.GetExecRequiredGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.GetGrade() <= this->sign_required_grade)
		this->is_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::CheckExecRequirements ( const Bureaucrat& b ) const
{
	if (b.GetGrade() > this->exec_required_grade)
		throw AForm::GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	AForm::GetName ( void ) const
{
	return (this->name);
}

bool		AForm::GetSignedState ( void ) const
{
	return (this->is_signed);
}

int			AForm::GetSignRequiredGrade ( void ) const
{
	return (this->sign_required_grade);
}

int			AForm::GetExecRequiredGrade ( void ) const
{
	return (this->exec_required_grade);
}

/*
** --------------------------------- Exceptions ----------------------------------
*/

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too High !");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}

/* ************************************************************************** */