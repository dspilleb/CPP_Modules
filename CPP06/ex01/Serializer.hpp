#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

typedef struct Data
{
	int value;
	std::string name;
} Data;

class Serializer
{

	public:

		Serializer();
		Serializer( Serializer const & src );
		virtual ~Serializer() = 0; //make it abstract

		Serializer &		operator=( Serializer const & rhs );
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:

};


#endif /* ****************************************************** SERIALIZER_H */