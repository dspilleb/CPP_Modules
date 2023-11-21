#ifndef WEAPON_HPP
# define WEAPON_HPP

# include<iostream>

class Weapon{
	private:
		std::string type;
	public:
		const	std::string& getType( void );
		void	setType( std::string new_type );
		Weapon( std::string set_type);
		Weapon( void );
		~Weapon( void );
};

#endif