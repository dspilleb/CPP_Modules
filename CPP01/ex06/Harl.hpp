#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl{

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		int get_level ( const std::string level) const;
	public:
		void complain( std::string level );
		Harl( void );
		~Harl ( void );
};

#endif