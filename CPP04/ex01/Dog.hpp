#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{

	public:

		Dog();
		Dog( Dog const & src );
		~Dog();

		Dog &		operator=( Dog const & rhs );
		virtual void makeSound( void ) const;
		Brain* getbrain( void );
	private:
		Brain* my_brain;
		
};

#endif /* ************************************************************* DOG_H */