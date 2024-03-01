#include "Bureaucrat.hpp"


char *GradeTooHighException::what()
{
	return ("Grade is too High !!");
}

char *GradeTooLowException::what()
{
	return ("Grade is too low !!");
}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string setname, int setgrade) : name(setname), grade(setgrade)
{
	if (this->grade > 150)
		throw GradeTooLowException();
	else if (this->grade < 1)
		throw GradeTooHighException();
	return;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.getName();
		this->grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName( void ) const
{
	return (this->name);
}
int Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

/* ************************************************************************** */