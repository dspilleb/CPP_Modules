#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define RED "\033[1;31m"
# define NONE "\033[0m"

class Zombie
{

	public:
		void announce( void );
		void set_name ( std::string given_name );
		Zombie();
		~Zombie( void );

	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif