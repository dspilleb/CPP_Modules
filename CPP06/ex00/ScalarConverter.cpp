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
	if (literal.length() == 1 && isprint(literal[0]))
		convert_from_char(literal);
	else if (literal.find_first_of('.f') == std::string::npos)
		convert_from_int(literal);
	else if (literal.find_
}

void convert_from_char(const std::string literal)
{
	return;
}
void convert_from_int(const std::string literal)
{
	return;
}
void convert_from_float(const std::string literal)
{
	return;
}
void convert_from_double(const std::string literal)
{
	return;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */