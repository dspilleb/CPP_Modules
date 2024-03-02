#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		void setBrainAtIndex(const std::string given_idea, const int index);
		std::string getBrainAtIndex( const int index) const;
		Brain &		operator=( Brain const & rhs );

	private:
		std::string ideas[100];

};

std::ostream &			operator<<( std::ostream & o, Brain const & i );

#endif /* *********************************************************** BRAIN_H */