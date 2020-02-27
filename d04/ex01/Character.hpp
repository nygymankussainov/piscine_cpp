#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"
# include "SuperMutant.hpp"
# include "RadScorpion.hpp"

class Character {

	private:

		std::string _name;
		int			_AP;
		AWeapon		*_currWeapon;

	public:

		Character( void );
		Character( std::string const & name );
		Character( Character const & src );
		~Character( void );
		Character &	operator=( Character const & rhs );

		void	recoveryAP( void );
		void	equip( AWeapon* );
		void	attack( Enemy* );
		std::string	const	getName( void ) const;
		int		getAP ( void ) const;
		AWeapon*	getAWeapon( void ) const;
};

std::ostream &	operator<<( std::ostream & o, Character const & rhs );

#endif
