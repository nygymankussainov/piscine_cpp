#ifndef STACK_HPP
# define STACK_HPP

# include "Fixed.class.hpp"

typedef struct	s_list {

	Fixed	fixedVal;
	char	c;
	bool	isFixedVal;
	bool	isChar;
	struct s_list *next;
}				t_list;

class Stack {

	public:

		t_list	*lst;

		Stack( void );
		Stack( Stack const & src );
		~Stack( void );

		Stack &	operator=( Stack const & rhs );
		Stack &	operator+( Stack const & rhs );
		Stack &	operator-( Stack const & rhs );
		Stack &	operator*( Stack const & rhs );
		Stack &	operator/( Stack const & rhs );
		bool	operator==( char c );
		bool	operator==( Fixed fixedVal );
		bool	operator!=( char c );
		bool	operator!=( Fixed fixedVal );
		void	push( Fixed fixedVal );
		void	push( char c );
		void	push( Stack const & val );
		void	queue( Fixed fixedVal );
		void	queue( char c );
		void	queue( Stack const & val );
		void	pop( void );
		bool	empty( void ) const;
		Stack &	top( void );
		int		getSize( void ) const;

	private:

		int _size;
};

std::ostream &	operator<<( std::ostream & o, Stack const & rhs );

#endif
