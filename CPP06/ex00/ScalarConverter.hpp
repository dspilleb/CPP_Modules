#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>

class ScalarConverter
{

	public:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );	
		virtual ~ScalarConverter() = 0; //make it abstract
		static void convert(const std::string literal);	
		ScalarConverter &		operator=( ScalarConverter const & rhs );

		static void convert_from_char(const std::string literal);
		static void convert_from_int(const std::string literal);
		static void convert_from_float(const std::string literal);
		static void convert_from_double(const std::string literal);
	private:

};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */