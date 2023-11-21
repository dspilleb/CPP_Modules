
#include "HumanB.hpp"

HumanB::HumanB(std::string set_name)
{
	this->name = set_name;
	return;
}

HumanB::~HumanB()
{
	return;
}

void HumanB::attack( void )
{
	std::cout << this->name + " attacks with their " << this->weapon.getType() << std::endl;
	return ;
}

void HumanB::setWeapon( Weapon new_Weapon)
{
	this->weapon = new_Weapon;
}