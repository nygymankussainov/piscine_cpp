#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include <stdexcept>

class Form {

	private:
		std::string const _name;
		std::string _target;
		bool	_isSigned;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		Form( void );
		Form( std::string name, std::string target, int gradeToSign, int gradeToExec );
		Form( Form const & src );
		Form &	operator=( Form const & rhs );
		virtual ~Form( void );

		bool	isSigned( void ) const;
		std::string const & getName( void ) const;
		std::string const & getTarget( void ) const;
		int		getGradeToSign( void ) const;
		int		getGradeToExec( void ) const;
		void	setTarget( std::string const & target );
		bool	beSigned( Bureaucrat const & b );
		virtual void	execute( Bureaucrat const & executor ) const = 0;

		class GradeTooHighException : public std::exception {

			public:
				GradeTooHighException( void );
				GradeTooHighException( GradeTooHighException const & src );
				GradeTooHighException & operator=( GradeTooHighException const & rhs );
				virtual ~GradeTooHighException( void ) throw();
				virtual const char* what( void ) const throw();

		};
		class GradeTooLowException : public std::exception {
			
			public:
				GradeTooLowException( void );
				GradeTooLowException( GradeTooLowException const & src );
				GradeTooLowException & operator=( GradeTooLowException const & rhs );
				virtual ~GradeTooLowException( void ) throw();
				virtual const char* what( void ) const throw();
		};
		class FormNotSignedException : public std::exception {

			public:
				FormNotSignedException( void );
				FormNotSignedException( FormNotSignedException const & src );
				FormNotSignedException & operator=( FormNotSignedException const & rhs );
				virtual ~FormNotSignedException( void ) throw();
				virtual const char* what( void ) const throw();
		};
};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif
