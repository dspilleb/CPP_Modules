#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{

	public:

		Form( Form const & src );
		Form(std::string set_name, bool set_signed_state, int set_sign_required_grade, int set_exec_required_grade);
		~Form();

		Form &		operator=( Form const & rhs );


		std::string	GetName ( void ) const;
		bool		GetSignedState ( void ) const;
		int			GetSignRequiredGrade ( void ) const;
		int			GetExecRequiredGrade ( void ) const;

		void		beSigned(const Bureaucrat & b); 

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
		Form();
		const	std::string	name;
		bool				is_signed;
		const	int			sign_required_grade;
		const	int			exec_required_grade;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */