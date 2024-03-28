#include "IMateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

IMateriaSource::IMateriaSource()
{
	return;
}

IMateriaSource::IMateriaSource( const IMateriaSource & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

IMateriaSource &				IMateriaSource::operator=( IMateriaSource const & rhs )
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