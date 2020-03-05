#ifndef  SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form {

	private:
		static const int _gradeToSign;
		static const int _gradeToExec;

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string const & target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );
		virtual ~ShrubberyCreationForm( void );
		
		virtual void	execute( Bureaucrat const & executor ) const;
};

#endif
