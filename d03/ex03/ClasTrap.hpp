#ifndef CLASTRAP_HPP
# define CLASTRAP_HPP

# include <iostream>

class ClasTrap {

	public:

		ClasTrap( void );
		ClasTrap( ClasTrap const & src ); //copy contructor
		~ClasTrap( void );

		ClasTrap &	operator=( ClasTrap const & rhs );
		void	rangedAttack( std::string const & target );
		void	meleeAttack( std::string const & target );
		void	fingerAttack( std::string const & target );
		void	nipplesAttack( std::string const & target );
		void	noContactAttack( std::string const & target );

	protected:

		int	_meleeAttackDmg;
		int	_rangedAttackDmg;
		int	_fingerAttackDmg;
		int	_nipplesAttackDmg;
		int	_noContactAttackDmg;
		int	_hitPoints;
		int	_maxHitPoints;
		int	_energyPoints;
		int	_maxEnergyPoints;
		int _lvl;
		std::string	_name;
		int	_armorDmgReduction;
		
		void	_takeDmg( unsigned int amount );
		void	_beRepaired( unsigned int amount );

};

#endif
