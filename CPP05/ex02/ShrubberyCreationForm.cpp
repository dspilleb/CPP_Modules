#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", false, 145, 137), target("Default") 
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm(src),  target(src.target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm ( std::string set_target ) : AForm("ShrubberyCreationForm", false, 145, 137), target(set_target)
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
		this->is_signed = rhs.is_signed;
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

	outfile.open(this->target + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	if (! (outfile.is_open() && outfile.good()))
	{
		std::cout << "Error while opening/creating file" << this->target + "_shrubbery" << std::endl;
		return;
	}
	outfile << "                                  # #### ####\n                                ### \\/#|### |/####\n                               ##\\/#/ \\||/##/_/##/_#\n                             ###  \\/###|/ \\/ # ###\n                           ##_\\_#\\_\\## | #/###_/_####\n                          ## #### # \\ #| /  #### ##/##\n                           __#_--###`  |{,###---###-~\n                                     \\ }{\n                                      }}{\n                                      }}{\n                                 ejm  {{}\n                                , -=-~{ .-^- _\n                                      `}\n                                       {";
	outfile.close();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */