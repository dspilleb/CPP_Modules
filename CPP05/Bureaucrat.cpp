#include "Bureaucrat.hpp"

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
	{
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