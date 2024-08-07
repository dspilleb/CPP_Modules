#include "Intern.hpp"

# define NB_FORMS 3
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	(void) src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void) rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *Intern::makeForm(const std::string type, const std::string target) const
{
	AForm *(*Constructors[NB_FORMS]) (const std::string) = {&AllocateForm<RobotomyRequestForm>, &AllocateForm<PresidentialPardonForm>, &AllocateForm<ShrubberyCreationForm>};
	const std::string FormNames[NB_FORMS] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int i = 0;
	while (i < NB_FORMS)
	{
		if (type == FormNames[i])
		{
			std::cout << "Intern creates " << FormNames[i] << std::endl;
			return (Constructors[i](target));
		}
		i++;
	}
	std::cout << "The Intern does not know the form \""<< type << "\"" <<std::endl; 
	return (NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */