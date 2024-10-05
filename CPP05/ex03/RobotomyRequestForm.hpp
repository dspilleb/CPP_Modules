#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <time.h>
# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm( std::string set_target );
		~RobotomyRequestForm();

		void	execute(Bureaucrat const & executor) const;

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

	private:
		RobotomyRequestForm();
		const std::string	_target;

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */