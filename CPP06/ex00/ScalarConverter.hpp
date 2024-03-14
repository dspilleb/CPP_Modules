#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>

class ScalarConverter
{

	public:

		enum type {INT, CHAR, FLOAT, DOUBLE, INVALID};
		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );	
		virtual ~ScalarConverter() = 0; //make it abstract
		static void convert(const std::string literal);	
		type get_type(const std::string &literal) const;
		ScalarConverter &		operator=( ScalarConverter const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */