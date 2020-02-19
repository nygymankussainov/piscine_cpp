#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:

		ScavTrap( void );
		ScavTrap( std::string name );
		~ScavTrap( void );

		void		challengeNewcomer( std::string const & target );
};

#endif
