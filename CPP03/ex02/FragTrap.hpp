#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

	public:

		FragTrap();
		FragTrap( FragTrap const & src );
		~FragTrap();
		FragTrap(std::string given_name);
		FragTrap &		operator=( FragTrap const & rhs );
		void highFivesGuys(void);

	private:

};

std::ostream &			operator<<( std::ostream & o, FragTrap const & i );

#endif /* ******************************************************** FRAGTRAP_H */