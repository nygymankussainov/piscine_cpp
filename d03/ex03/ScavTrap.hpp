#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClasTrap.hpp"

class ScavTrap : ClasTrap {

	public:

		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src ); //copy contructor
		~ScavTrap( void );

		ScavTrap &	operator=( ScavTrap const & rhs );
		void	challengeNewcomer(std::string const & target);
		std::string	getName( void ) const;
};

#endif
