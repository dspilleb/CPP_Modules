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
	for (int i = 0; i < NB_FORMS; i++) {
		if (type == FormNames[i]){
			std::cout << "Intern creates " << FormNames[i] << std::endl;
			return (Constructors[i](target));
		}
	}
	std::cout << "The Intern doesn't know the form \""<< type << "\"" <<std::endl; 
	return (NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */