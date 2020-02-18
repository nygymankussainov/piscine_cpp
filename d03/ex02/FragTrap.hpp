#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:

		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		~FragTrap( void );

		FragTrap &	operator=( FragTrap const & rhs );
		std::string	getName( void ) const;
		uint32_t	getEP( void ) const;
		uint32_t	getMaxEP( void ) const;
		uint32_t	getMAdmg( void ) const;
		uint32_t	getRAdmg( void ) const;
		uint32_t	getArmorDmgRed( void ) const;

		void		rangedAttack( std::string const & target );
		void		meleeAttack( std::string const & target );
		void		vaulthunter_dot_exe( std::string const & target );

	private:

		uint32_t	_EP;
		uint32_t	_maxEP;
		std::string	_name;
		uint32_t	_MAdmg;
		uint32_t	_RAdmg;
		uint32_t	_armorDmgRed;

		void		_takeDamage( uint32_t amount );
};

#endif
