#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {

	private:
		static const int _gradeToSign;
		static const int _gradeToExec;

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string const & target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );
		virtual ~PresidentialPardonForm( void );

		virtual void	execute( Bureaucrat const & executor ) const;
};

#endif
