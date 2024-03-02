#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		//Constructors
		Bureaucrat(std::string name, int setgrade); // can throw
		Bureaucrat( Bureaucrat const & src );

		~Bureaucrat();
	
		/*Increment and decrement grade --> Since grade 1 is the highest one and 150 the lowest,
		incrementing a grade 3 should give a grade 2 to the bureaucrat.*/

		Bureaucrat &	operator=( Bureaucrat const & rhs );

		std::string		getName( void ) const;
		int				getGrade( void ) const;


		class GradeTooHighException : std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		Bureaucrat();
		std::string const name;
		int grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */