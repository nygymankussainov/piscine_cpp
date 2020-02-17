#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap {

	public:

		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src ); //copy contructor
		~ScavTrap( void );

		ScavTrap &	operator=( ScavTrap const & rhs );
		void	challengeNewcomer(std::string const & target);
		void	rangedAttack( std::string const & target );
		void	meleeAttack( std::string const & target );
		void	fingerAttack( std::string const & target );
		void	nipplesAttack( std::string const & target );
		void	noContactAttack( std::string const & target );

	private:

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
