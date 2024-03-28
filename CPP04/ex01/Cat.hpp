#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{

	public:

		Cat();
		Cat( Cat const & src );
		~Cat();

		Cat &		operator=( Cat const & rhs );
		virtual void makeSound( void ) const;
		Brain* getbrain( void );
	private:
		Brain* my_brain;
};


#endif /* ************************************************************* CAT_H */