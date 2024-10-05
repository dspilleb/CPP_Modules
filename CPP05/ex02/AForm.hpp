#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{

	public:

		AForm( AForm const & src );
		AForm(std::string set_name, int set_sign_required_grade, int set_exec_required_grade);
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );


		const std::string	&GetName ( void ) const;
		bool		GetSignedState ( void ) const;
		int			GetSignRequiredGrade ( void ) const;
		int			GetExecRequiredGrade ( void ) const;
		void		beSigned(const Bureaucrat & b); 

		virtual void		execute(Bureaucrat const & executor) const = 0;
	
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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		AForm();
	protected:
		void		CheckExecRequirements ( const Bureaucrat& b  ) const;
		const	std::string	_name;
		bool				_is_signed;
		const	int			_sign_required_grade;
		const	int			_exec_required_grade;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ FORM_H */