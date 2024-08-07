#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		AForm *makeForm(const std::string type, const std::string target) const;
		template <typename T> static AForm *AllocateForm(const std::string target) { return new T(target);};
	private:

};

#endif /* ********************************************************** INTERN_H */