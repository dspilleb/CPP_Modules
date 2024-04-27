#include "ICharacter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ICharacter::ICharacter()
{
	return;
}

ICharacter::ICharacter( const ICharacter & src )
{
	*this = src;
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ICharacter &				ICharacter::operator=( ICharacter const & rhs )
{
	(void) rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */