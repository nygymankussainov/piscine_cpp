#include "Fixed.class.hpp"
#include "Stack.hpp"
#include <sstream>
#include <ctype.h>

bool	isOperator( char c ) {

	if ( c == '(' || c == ')' ||
			c == '+' || c == '-' ||
			c == '*' || c == '/' )
		return true;

	return false;
}

void	getReversePolishNotation( Stack & stack, std::string exp ) {

	Stack operators;

	for (int i = 0; i < exp.length(); ++i) {

		if ( isdigit(exp[i]) ) {

			Fixed fix = std::stof( &exp[i] );
			stack.queue( fix );
			while (i < exp.length() && (isdigit(exp[i]) || exp[i] == '.'))
				++i;
		}
		if ( isOperator(exp[i]) ) {

			if ( !operators.empty() && (exp[i] == '*' || exp[i] == '/') &&
					(operators.top() == '*' || operators.top() == '/' )) {

				stack.queue( operators.top() );
				operators.pop();
			}
			if ( exp[i] == ')' ) {

				while ( operators.top() != '(' )
				{
					stack.queue( operators.top() );
					operators.pop();
				}
				operators.pop();
			}
			if ( exp[i] != ')' )
				operators.push( exp[i] );
		}
	}
	while ( !operators.empty() ) {

		stack.queue( operators.top() );
		operators.pop();
	}
}

Fixed	evaluateExpression( Stack & rpn ) {

	Stack res;

	while ( !rpn.empty() ) {

		if ( rpn.top().lst->isChar ) {

			Stack tmp = res.top();
			res.pop();
			if ( rpn.empty() )
				break;
			if ( rpn.top() == '+' )
				tmp = tmp + res.top();
			else if ( rpn.top() == '-' )
				tmp = tmp - res.top();
			else if ( rpn.top() == '*' )
				tmp = tmp * res.top();
			else
				tmp = tmp / res.top();
			res.pop();
			res.push( tmp );
			rpn.pop();
		}
		else {
			res.push( rpn.top() );
		}
		rpn.pop();
	}

	return res.lst->fixedVal;
}

int		main( int argc, char **argv ) {

	if ( argc < 2 )
		return 0;
	std::string exp( argv[argc - 1] );
	Stack rpn;

	getReversePolishNotation( rpn, exp );
	Fixed res = evaluateExpression( rpn );
	std::cout << res << std::endl;
	return 0;
}
