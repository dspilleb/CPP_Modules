#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
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
	(void) rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i )
{
	(void) i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ScalarConverter::convert(const std::string literal)
{
    double double_conversion;
	bool is_round;

	double_conversion = atof(literal.c_str());
	is_round = floor(double_conversion) == double_conversion;

	if (!is_valid_input(literal))
		std::cout << "Wrong input format, please write a valid string representation of a C++ literal (char/int/float/double)" << std::endl;
	else if (is_round && double_conversion >= std::numeric_limits<char>::min() && double_conversion <= std::numeric_limits<char>::max())
		convert_from_char(literal);
	else if (is_round && double_conversion >= std::numeric_limits<int>::min() && double_conversion <= std::numeric_limits<int>::max())
		convert_from_int(literal);
	else if (double_conversion >= std::numeric_limits<float>::min() && double_conversion <= std::numeric_limits<float>::max())
		convert_from_float(literal);
	else
		convert_from_double(literal);
}

void ScalarConverter::convert_from_char(const std::string &literal)
{
    char char_conversion;
    int int_conversion;
    float float_conversion;
    double double_conversion;

	char_conversion = atoi(literal.c_str());
    int_conversion = static_cast<int> (char_conversion);
    float_conversion = static_cast<float> (char_conversion);
    double_conversion = static_cast<double> (char_conversion);

    std::cout << "char: " << std::flush;
	if (isprint(char_conversion))
		std::cout << "'" << char_conversion << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << int_conversion << std::endl;
	std::cout << "float: " << float_conversion << ".0f" << std::endl;
	std::cout << "double: " << double_conversion << ".0" << std::endl;
	return;
}
void ScalarConverter::convert_from_int(const std::string &literal)
{
    int int_conversion;
    float float_conversion;
    double double_conversion;

	std::cout << "char: impossible" << std::endl;
	int_conversion = atoi(literal.c_str());
    float_conversion = static_cast<float> (int_conversion);
    double_conversion = static_cast<double> (int_conversion);

	std::cout << "int: " << int_conversion << std::endl;
	std::cout << "float: " << float_conversion << ".0f" << std::endl;
	std::cout << "double: " << double_conversion << ".0" << std::endl;

	return;
}

void ScalarConverter::convert_from_float(const std::string &literal)
{
    float float_conversion;
    double double_conversion;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	float_conversion = atof(literal.c_str());
	double_conversion = static_cast<double> (float_conversion);
	std::cout << "float: " << float_conversion << (floor(float_conversion) == float_conversion ? ".0" : "") << "f" <<std::endl;
	std::cout << "double: " << double_conversion <<(floor(double_conversion) == double_conversion ? ".0" : "") << std::endl;
	return;
}
void ScalarConverter::convert_from_double(const std::string &literal)
{
    double double_conversion;

	double_conversion = atof(literal.c_str());
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (isinf(double_conversion) || isnan(double_conversion))
	{
		std::cout << "float: " << (double_conversion > 0 ? "+" : "") << double_conversion << "f" << std::endl;
		std::cout << "double: " << (double_conversion > 0 ? "+" : "") << double_conversion << std::endl;
	}
	else
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << double_conversion <<(floor(double_conversion) == double_conversion ? ".0" : "") << std::endl;
	}
	return;
}

bool ScalarConverter::is_valid_input (const std::string &literal)
{
	int point_indx = -1;
	if (literal == "inf" || literal == "+inf" || literal == "-inf" || 
		literal == "inff" || literal == "+inff" || literal == "-inff" ||
		literal == "nan" || literal == "nanf")
		return (true);

	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
		{
			if (literal[i] == '-' && i == 0);
			else if (literal[i] == 'f' && i == (literal.length() - 1));
			else if (literal[i] == '.' && point_indx < 0 && literal.length() > 1)
			{
				point_indx = i;
			}
			else
				return (false);
		}
	}
	return (true);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */