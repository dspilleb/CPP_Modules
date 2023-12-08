#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define GREEN "\033[0;32m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[0;33m"
# define RED "\033[1;31m"
# define BWHITE "\033[1;37m"
# define BBLACK "\033[1;30m"
# define MAGENTA "\033[1;35m"

class ClapTrap
{

	protected:
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
	public:

		ClapTrap( void );
		ClapTrap( std::string given_name );
		ClapTrap( ClapTrap const & src );
		~ClapTrap( void );

		ClapTrap &		operator=( ClapTrap const & rhs );
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif