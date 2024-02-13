
#include "HumanB.hpp"

HumanB::HumanB(std::string set_name)
{
	this->name = set_name;
	this->weapon = NULL;
	return;
}

HumanB::~HumanB()
{
	return;
}

void HumanB::attack( void )
{
	if (weapon)
		std::cout << this->name + " attacks with their " << (*this->weapon).getType() << std::endl;
	else
		std::cout << this->name + " has no weapon." << std::endl;
	return ;
}

void HumanB::setWeapon( Weapon &new_Weapon)
{
	this->weapon = &new_Weapon;
}