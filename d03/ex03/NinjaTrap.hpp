#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class NinjaTrap : public ClapTrap {

	public:

		NinjaTrap( void );
		NinjaTrap( std::string name );
		~NinjaTrap( void );

		void		ninjaShoebox( FragTrap const & ft );
		void		ninjaShoebox( ScavTrap const & st );
		void		ninjaShoebox( NinjaTrap const & nt );
};

#endif
