#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : 
AForm("Default", 72, 45), _target("Default")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : 
AForm(src),  _target(src._target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm ( std::string set_target ) : 
AForm("RobotomyRequestForm", 72, 45), _target(set_target)
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
		_is_signed = _is_signed;
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
	srand(time(NULL));
	if ((rand() % 2) == 0)
		std::cout <<  this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << " robotomy failed" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */