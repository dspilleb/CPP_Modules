#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure")
{
	return;
}

Cure::Cure( const Cure & src ) : AMateria(src.getType())
{
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	(void) rhs;
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria* Cure::clone() const
{
	return (new(std::nothrow) Cure());
}
void Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string const & Cure::getType() const{
	return (this->materia_type);
}

/* ************************************************************************** */