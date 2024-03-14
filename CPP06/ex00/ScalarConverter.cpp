#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
	return;
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i )
{
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ScalarConverter::convert(const std::string literal)
{
}

ScalarConverter::type ScalarConverter::get_type(const std::string &literal) const
{
	std::size_t dot_pos;
	std::size_t f_character_pos;

	if (literal.find_first_not_of("0123456789.f") != std::string::npos)
		return INVALID;
	dot_pos = literal.find('.');
	f_character_pos = literal.find('f');

	if (literal.fin)

	// if (dot_pos == std::string::npos && f_character_pos == std::string::npos)
	// 	return INT;
	// else
	
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */