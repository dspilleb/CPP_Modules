#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define RED "\033[1;31m"
# define NONE "\033[0m"

class Zombie
{
	private:
		std::string name;

	public:
		void announce( void );
		static Zombie *newZombie( std::string name);
		static void randomChump( std::string name);
		Zombie ( void );
		Zombie( std::string name );
		~Zombie( void );
};

#endif