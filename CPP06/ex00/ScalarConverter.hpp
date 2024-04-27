#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <limits>
# include <cstdlib>
# include <cfloat>
# include <cmath>

class ScalarConverter
{

	public:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );	
		virtual ~ScalarConverter() = 0; //make it abstract
		static void convert(const std::string literal);	
		ScalarConverter &		operator=( ScalarConverter const & rhs );

	private:
		static void convert_from_char(const std::string &literal);
		static void convert_from_int(const std::string &literal);
		static void convert_from_float(const std::string &literal);
		static void convert_from_double(const std::string &literal);
		static bool is_valid_input (const std::string &literal);

};


#endif /* ************************************************* SCALARCONVERTER_H */