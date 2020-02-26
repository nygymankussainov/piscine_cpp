#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon {

	protected:
		
		std::string _name;
		int			_damage;
		int			_apcost;

	public:

		AWeapon( void );
		AWeapon( std::string const & name, int apcost, int damage );
		AWeapon( AWeapon const & src );
		AWeapon &	operator=( AWeapon const & rhs );
		virtual ~AWeapon( void );
		std::string	const getName( void ) const;
		int	getAPCost( void ) const;
		int getDamage( void ) const;
		virtual void	attack( void ) const = 0;

};

class PlasmaRifle : public AWeapon {

	public:

		PlasmaRifle( void );
		PlasmaRifle( PlasmaRifle const & src );
		PlasmaRifle &	operator=( PlasmaRifle const & rhs );
		virtual ~PlasmaRifle( void );

		virtual void	attack( void ) const;
};

class PowerFist : public AWeapon {

	public:

		PowerFist( void );
		PowerFist( PowerFist const & src );
		PowerFist &	operator=( PowerFist const & rhs );
		virtual ~PowerFist( void );

		virtual void	attack( void ) const;
};

#endif
