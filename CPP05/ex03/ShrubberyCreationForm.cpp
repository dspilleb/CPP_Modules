#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : 
AForm("Default", 145, 137), _target("Default") 
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : 
AForm(src),  _target(src._target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm ( std::string set_target ) : 
AForm("ShrubberyCreationForm", 145, 137), _target(set_target)
{
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		_is_signed = rhs._is_signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << i.GetName() << (i.GetSignedState() ? ", is signed" : ", is not signed") ;
	o << ", required grade to sign : " << i.GetSignRequiredGrade();
	o << ", required grade to execute : " << i.GetExecRequiredGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->CheckExecRequirements(executor);
	std::ofstream outfile;

	outfile.open((_target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (! (outfile.is_open() && outfile.good()))
	{
		std::cout << "Error while opening/creating file" << _target + "_shrubbery" << std::endl;
		return;
	}
	outfile << "                                  # #### ####\n                                ### \\/#|### |/####\n                               ##\\/#/ \\||/##/_/##/_#\n                             ###  \\/###|/ \\/ # ###\n                           ##_\\_#\\_\\## | #/###_/_####\n                          ## #### # \\ #| /  #### ##/##\n                           __#_--###`  |{,###---###-~\n                                     \\ }{\n                                      }}{\n                                      }}{\n                                 ejm  {{}\n                                , -=-~{ .-^- _\n                                      `}\n                                       {";
	outfile.close();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */