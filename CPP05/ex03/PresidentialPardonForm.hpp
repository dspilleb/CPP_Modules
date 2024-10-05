#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm( PresidentialPardonForm const & src );
		PresidentialPardonForm ( std::string set_target );
		~PresidentialPardonForm();

		void	execute(Bureaucrat const & executor) const;

		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );

	private:
		PresidentialPardonForm();
		const std::string	_target;
};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */