#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

	public:

		ClapTrap( void );
		ClapTrap( ClapTrap const & src );
		~ClapTrap( void );

		ClapTrap &	operator=( ClapTrap const & rhs );
		void	setAttributes( std::string name, uint32_t HP, uint32_t maxHP,
			   uint32_t EP, uint32_t maxEP, uint32_t lvl,
			   uint32_t MAdmg, uint32_t RAdmg, uint32_t armorDmgRed );
		std::string	getName( void ) const;
		uint32_t	getHP( void ) const;
		uint32_t	getMaxHP( void ) const;
		uint32_t	getEP( void ) const;
		uint32_t	getMaxEP( void ) const;
		uint32_t	getlvl( void ) const;
		uint32_t	getMAdmg( void ) const;
		uint32_t	getRAdmg( void ) const;
		uint32_t	getArmorDmgRed( void ) const;

		void	rangedAttack( std::string const & target );
		void	meleeAttack( std::string const & target );

	protected:

		std::string	_name;
		uint32_t	_HP;
		uint32_t	_maxHP;
		uint32_t	_EP;
		uint32_t	_maxEP;
		uint32_t	_lvl;
		uint32_t	_MAdmg;
		uint32_t	_RAdmg;
		uint32_t	_armorDmgRed;

		void		_takeDamage( uint32_t amount );
		void		_beRepaired( uint32_t amount );
};

#endif
