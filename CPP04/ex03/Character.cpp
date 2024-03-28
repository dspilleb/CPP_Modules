#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(std::string given_name) : ICharacter()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->name = given_name;
	return;
}

Character::Character( const Character & src ) : ICharacter(src)
{
	*this = src;
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->inventory[i];
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
		this->name = rhs.name;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4 && this->inventory[i])
		i++;
	if (i <= 3)
		this->inventory[i] = m;
	else
		std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Index out of range" << std::endl;
	else if (this->inventory[idx])
		this->inventory[idx] = NULL;
	else
		std::cout << "No Materia at this index" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Index out of range" << std::endl;
	else if (!this->inventory[idx])
		std::cout << "No Materia at this index" << std::endl;
	else
		this->inventory[idx]->use(target);
	return;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName() const
{
	return (this->name);
}


/* ************************************************************************** */