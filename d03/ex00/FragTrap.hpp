#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap {

	public:

		FragTrap( std::string name );
		FragTrap( FragTrap const & src ); //copy contructor
		~FragTrap( void );

		FragTrap &	operator=( FragTrap const & rhs );
		void	vaulthunter_dot_exe(std::string const & target);
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
