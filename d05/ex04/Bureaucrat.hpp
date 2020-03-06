#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Form;

class Bureaucrat {

	private:
		std::string _name;
		int	_grade;
		bool _signer;
		bool _executor;

	public:
		Bureaucrat( void );
		Bureaucrat( std::string const & name, int grade );
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat & operator=( Bureaucrat const & rhs );
		~Bureaucrat( void );

		void	incrementGrade( void );
		void	decrementGrade( void );
		std::string const &	getName( void ) const;
		int		getGrade( void ) const;
		void	setGrade( int amount );
		void	setSigner( void );
		void	setExecutor( void );
		void	signForm( Form & f );
		bool	isSigner( void ) const;
		bool	isExecutor( void ) const;

		void	executeForm( Form const & form );
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
};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif
