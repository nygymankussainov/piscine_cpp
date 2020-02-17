#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include "ClasTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap : ClasTrap {

	public:

		NinjaTrap( std::string name );
		NinjaTrap( NinjaTrap const & src ); //copy contructor
		~NinjaTrap( void );

		NinjaTrap &	operator=( NinjaTrap const & rhs );
		void	ninjaShoebox( FragTrap & ft );
		void	ninjaShoebox( ScavTrap & st );
		void	ninjaShoebox( NinjaTrap & nt );
		std::string	getName( void ) const;
};

#endif
