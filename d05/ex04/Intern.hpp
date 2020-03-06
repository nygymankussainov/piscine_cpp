#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

	public:
		Intern( void );
		Intern( Intern const & src );
		Intern & operator=( Intern const & rhs );
		~Intern( void );

		Form *	makeForm( std::string const & name, std::string const & target );
		class UnknownFormException : public std::exception {

			public:
				UnknownFormException( void );
				UnknownFormException( UnknownFormException const & src );
				UnknownFormException & operator=( UnknownFormException const & rhs );
				virtual ~UnknownFormException( void ) throw();

				virtual const char* what( void ) const throw();
		};
};

#endif
