#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"
# include "TacticalMarine.hpp"
# include "AssaultTerminator.hpp"
# include <iostream>

typedef struct	s_units {

	ISpaceMarine*	marine;
	int				index;
	struct s_units	*next;
}				t_units;

class Squad : public ISquad {

	private:
		int			_unitNb;
		t_units*	units;
		void	_destroyUnits( void );
		void	_copyUnits( Squad const & src );

	public:
		Squad( void );
		Squad( Squad const & src );
		Squad &	operator=( Squad const & rhs );
		virtual ~Squad( void );
		t_units	*find_unit( t_units* units, ISpaceMarine* marine );

		virtual int getCount( void ) const;
		virtual ISpaceMarine* getUnit( int ) const;
		virtual int push( ISpaceMarine* );
};

#endif
