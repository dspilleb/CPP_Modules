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
	if (literal.find_first_not_of("0123456789.f") != std::string::npos)
		return INVALID;

}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */