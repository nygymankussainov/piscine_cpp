#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

	public:

		ClapTrap( void );
		ClapTrap( ClapTrap const & src );
		~ClapTrap( void );

		ClapTrap &	operator=( ClapTrap const & rhs );
		uint32_t	getHP( void ) const;
		uint32_t	getMaxHP( void ) const;
		uint32_t	getlvl( void ) const;


	protected:

		uint32_t	_HP;
		uint32_t	_maxHP;
		uint32_t	_lvl;

		void		_beRepaired( uint32_t amount );
};

#endif
