#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon* weapon;
		std::string name;
	public:
		void attack( void );
		HumanA(std::string set_name, Weapon &set_weapon);
		~HumanA( void );
};

#endif