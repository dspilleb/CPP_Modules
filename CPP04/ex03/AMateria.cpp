#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria(std::string const & type) : materia_type(type)
{
	return;
}

AMateria::AMateria( const AMateria & src ) : materia_type(src.getType())
{
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		this->materia_type = rhs.getType();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AMateria::use(ICharacter& target)
{
	(void) target;
	return;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & AMateria::getType() const
{
	return (this->materia_type);
}


/* ************************************************************************** */