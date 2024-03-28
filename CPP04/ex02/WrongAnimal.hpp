#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();
		const std::string& getType( void ) const;

		WrongAnimal &		operator=( WrongAnimal const & rhs );
		void makeSound( void ) const;

	protected:
		std::string type;

};

#endif /* ***************************************************** WRONGANIMAL_H */