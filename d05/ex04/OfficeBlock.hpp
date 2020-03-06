#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"

class OfficeBlock {

	private:
		Intern* _intern;
		Bureaucrat* _signer;
		Bureaucrat* _executor;

	public:
		OfficeBlock( void );
		OfficeBlock( Intern & intern, Bureaucrat & signer, Bureaucrat & executor );
		~OfficeBlock( void );

		Intern * getIntern( void ) const;
		Bureaucrat * getSigner( void ) const;
		Bureaucrat * getExecutor( void ) const;

		void	setIntern( Intern & intern );
		void	setSigner( Bureaucrat & signer );
		void	setExecutor( Bureaucrat & executor );
		
		void	doBureaucraccy( std::string const & name, std::string const & target );
		
		class NoInternException : public std::exception {

			public:
				NoInternException( void );
				NoInternException( NoInternException const & src );
				NoInternException & operator=( NoInternException const & rhs );
				virtual ~NoInternException( void ) throw();
				virtual const char* what( void ) const throw();
		};

		class NoSignerException : public std::exception {

			public:
				NoSignerException( void );
				NoSignerException( NoSignerException const & src );
				NoSignerException & operator=( NoSignerException const & rhs );
				virtual ~NoSignerException( void ) throw();
				virtual const char* what( void ) const throw();
		};

		class NoExecutorException : public std::exception {

			public:
				NoExecutorException( void );
				NoExecutorException( NoExecutorException const & src );
				NoExecutorException & operator=( NoExecutorException const & rhs );
				virtual ~NoExecutorException( void ) throw();
				virtual const char* what( void ) const throw();
		};
};

#endif
