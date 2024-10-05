#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm ( std::string set_target );
		~ShrubberyCreationForm();


		void	execute(Bureaucrat const & executor) const;


		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

	private:
		ShrubberyCreationForm();
		const std::string	_target;
};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */