#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		Bureaucrat(std::string name, int setgrade);
		Bureaucrat( Bureaucrat const & src );

		~Bureaucrat();

		void increment( void );
		void decrement( void );

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