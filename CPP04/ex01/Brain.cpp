#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << YELLOW << "Brain : Default constructor called" << NONE << std::endl;
	return;
}

Brain::Brain( const Brain & src )
{
	std::cout << YELLOW << "Brain: Copy constructor called" << NONE << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << YELLOW << "Brain: Destructor called" << NONE << std::endl;
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void Brain::setBrainAtIndex(const std::string given_idea, const int index)
{
	if (index < 0 || index >= 100)
		std::cout << RED "Bad brain index, can't set value" << std::endl;
	else
		this->ideas[index] = given_idea;
	return; 
}

std::string Brain::getBrainAtIndex( const int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cout << RED "Bad brain index, can't get value" << std::endl;
		return ("");
	}
	return (this->ideas[index]);
}


/* ************************************************************************** */