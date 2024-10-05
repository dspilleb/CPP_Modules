#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class AForm;

# define R "\x1b[1;31m"
# define G "\x1b[1;32m"
# define B "\x1b[1;36m"
# define Y "\x1b[1;33m"
# define M "\x1b[1;35m"
# define C "\x1b[0m"

class Bureaucrat
{

	public:

		Bureaucrat(std::string name, int setgrade);
		Bureaucrat( Bureaucrat const & src );

		~Bureaucrat();

		void increment( void );
		void decrement( void );
		void signForm( AForm& f) const;
		void executeForm(AForm const & form) const;
	
		Bureaucrat &	operator=( Bureaucrat const & rhs );

		std::string		GetName( void ) const;
		int				GetGrade( void ) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		Bureaucrat();
		std::string const _name;
		int _grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */