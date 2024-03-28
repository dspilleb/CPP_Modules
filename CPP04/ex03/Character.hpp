#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{

	public:

		Character(std::string given_name);
		Character( Character const & src );
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		Character &		operator=( Character const & rhs );

	private:
		AMateria *inventory[4];
		std::string name;
};


#endif /* ******************************************************* CHARACTER_H */