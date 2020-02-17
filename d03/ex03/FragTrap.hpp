#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClasTrap.hpp"

class FragTrap : ClasTrap {

	public:

		FragTrap( std::string name );
		FragTrap( FragTrap const & src ); //copy contructor
		~FragTrap( void );

		FragTrap &	operator=( FragTrap const & rhs );
		void	vaulthunter_dot_exe(std::string const & target);
		std::string	getName( void ) const;

};

#endif
