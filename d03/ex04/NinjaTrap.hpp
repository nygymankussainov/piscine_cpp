#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap {

	public:

		NinjaTrap( void );
		NinjaTrap( std::string name );
		virtual ~NinjaTrap( void );

		void		ninjaShoebox( FragTrap const & ft );
		void		ninjaShoebox( ScavTrap const & st );
		void		ninjaShoebox( NinjaTrap const & nt );
};

#endif
