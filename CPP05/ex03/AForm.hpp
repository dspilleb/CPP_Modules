#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{

	public:

		AForm( AForm const & src );
		AForm(std::string set_name, bool set_signed_state, int set_sign_required_grade, int set_exec_required_grade);
		virtual	~AForm();

		AForm &		operator=( AForm const & rhs );


		std::string	GetName ( void ) const;
		bool		GetSignedState ( void ) const;
		int			GetSignRequiredGrade ( void ) const;
		int			GetExecRequiredGrade ( void ) const;

		virtual void	execute(Bureaucrat const & executor) const = 0;
		void		CheckExecRequirements ( const Bureaucrat& b  ) const;
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
		AForm();
	protected:
		const	std::string	name;
		bool				is_signed;
		const	int			sign_required_grade;
		const	int			exec_required_grade;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ FORM_H */