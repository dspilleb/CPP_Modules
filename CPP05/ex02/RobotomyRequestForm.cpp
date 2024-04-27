#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", false, 72, 45), target("Default")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : AForm(src),  target(src.target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm ( std::string set_target ) : AForm("RobotomyRequestForm", false, 72, 45), target(set_target)
{
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->is_signed = rhs.is_signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << i.GetName() << (i.GetSignedState() ? ", is signed" : ", is not signed") ;
	o << ", required grade to sign : " << i.GetSignRequiredGrade();
	o << ", required grade to execute : " << i.GetExecRequiredGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->CheckExecRequirements(executor);
	std::cout << "Bzzzzzzzzzz";
	if ((rand() % 2) == 0)
		std::cout <<  this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << " robotomy failed" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */