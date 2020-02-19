#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : virtual public FragTrap, virtual public NinjaTrap {

	public:

		SuperTrap( void );
		SuperTrap( std::string name );
		virtual ~SuperTrap( void );

};

#endif
