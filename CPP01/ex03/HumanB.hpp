#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		Weapon* weapon;
		std::string name;
	public:
		void attack( void );
		void setWeapon( Weapon &new_weapon );
		HumanB(std::string set_name);
		~HumanB( void );
};

#endif