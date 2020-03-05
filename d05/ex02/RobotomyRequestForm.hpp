#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form {

	private:
		static const int _gradeToSign;
		static const int _gradeToExec;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const & target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs );
		virtual ~RobotomyRequestForm( void );

		virtual void	execute( Bureaucrat const & executor ) const;
};

#endif
