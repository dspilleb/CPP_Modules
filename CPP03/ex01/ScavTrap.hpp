#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	public:

		ScavTrap( void );
		// ScavTrap( ScavTrap const & src );
		ScavTrap ( std::string given_name);
		~ScavTrap( void );
		void attack(const std::string& target);
		void guardGate ( void );

		// ScavTrap &		operator=( ScavTrap const & rhs );

	private:

};

// std::ostream &			operator<<( std::ostream & o, ScavTrap const & i );

#endif