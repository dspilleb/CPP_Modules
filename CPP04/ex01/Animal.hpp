#ifndef ANIMAL_HPP
# define ANIMAL_HPP

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

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();
		const std::string& getType( void ) const;

		Animal &		operator=( Animal const & rhs );
		virtual void makeSound( void ) const;

	protected:
		std::string type;

};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif /* ********************************************************** ANIMAL_H */