#include "Stack.hpp"

Stack::Stack( void ) {

	this->_size = 0;
	this->lst = NULL;
	return;
}

Stack::Stack( Stack const & src ) {

	*this = src;
}

Stack::~Stack( void ) {

	while (this->lst) {

		pop();
	}
	return;
}

Stack &	Stack::operator=( Stack const & rhs ) {

	if (this != &rhs) {

		this->lst->fixedVal = rhs.lst->fixedVal;
		this->lst->isFixedVal = rhs.lst->isFixedVal;
		this->lst->c = rhs.lst->c;
		this->lst->isChar = rhs.lst->isChar;
		this->_size = rhs._size;
	}
	return *this;
}

Stack &	Stack::operator+( Stack const & rhs ) {

	this->lst->fixedVal = this->lst->fixedVal + rhs.lst->fixedVal;
	return *this;
}


Stack &	Stack::operator-( Stack const & rhs ) {

	this->lst->fixedVal = this->lst->fixedVal - rhs.lst->fixedVal;
	return *this;
}

Stack &	Stack::operator*( Stack const & rhs ) {

	this->lst->fixedVal = this->lst->fixedVal * rhs.lst->fixedVal;
	return *this;
}

Stack &	Stack::operator/( Stack const & rhs ) {

	this->lst->fixedVal = this->lst->fixedVal / rhs.lst->fixedVal;
	return *this;
}

bool	Stack::operator==( char c ) {

	if (this->lst->isChar && this->lst->c == c)
		return true;

	return false;
}

bool	Stack::operator==( Fixed fixedVal ) {

	if (this->lst->isFixedVal && this->lst->fixedVal == fixedVal)
		return true;

	return false;
}

bool	Stack::operator!=( char c ) {

	if (this->lst->isChar && this->lst->c != c)
		return true;

	return false;
}

bool	Stack::operator!=( Fixed fixedVal ) {

	if (this->lst->isFixedVal && this->lst->fixedVal != fixedVal)
		return true;

	return false;
}

void	Stack::push( Stack const & val ) {

	++this->_size;
	t_list	*newList = new t_list;
	newList->fixedVal = 0;
	newList->isFixedVal = false;
	newList->c = 0;
	newList->isChar = false;
	if (val.lst->isFixedVal) {
		newList->fixedVal = val.lst->fixedVal;
		newList->isFixedVal = val.lst->isFixedVal;
	}
	else if (val.lst->isChar) {
		newList->c = val.lst->c;
		newList->isChar = val.lst->isChar;
	}
	newList->next = this->lst;
	this->lst = newList;
}

void	Stack::push( Fixed fixedVal ) {

	++this->_size;
	t_list	*newList = new t_list;
	newList->fixedVal = fixedVal;
	newList->isFixedVal = true;
	newList->isChar = false;
	newList->next = this->lst;
	this->lst = newList;
}

void	Stack::push( char c ) {

	++this->_size;
	t_list	*newList = new t_list;
	newList->c = c;
	newList->isChar = true;
	newList->isFixedVal = false;
	newList->next = this->lst;
	this->lst = newList;
}

void	Stack::queue( Stack const & val ) {

	++this->_size;
	t_list	*newList = new t_list;
	newList->fixedVal = 0;
	newList->isFixedVal = false;
	newList->c = 0;
	newList->isChar = false;
	if (val.lst->isFixedVal) {
		newList->fixedVal = val.lst->fixedVal;
		newList->isFixedVal = val.lst->isFixedVal;
	}
	else if (val.lst->isChar) {
		newList->c = val.lst->c;
		newList->isChar = val.lst->isChar;
	}
	newList->next = NULL;
	if (this->lst == NULL)
		this->lst = newList;
	else {

		t_list *tmp = this->lst;
		while ( tmp->next ) {

			tmp = tmp->next;
		}
		tmp->next = newList;
	}
}

void	Stack::queue( Fixed fixedVal ) {

	++this->_size;
	t_list	*newList = new t_list;
	newList->fixedVal = fixedVal;
	newList->isFixedVal = true;
	newList->isChar = false;
	newList->next = NULL;
	if (this->lst == NULL)
		this->lst = newList;
	else {

		t_list *tmp = this->lst;
		while ( tmp->next ) {

			tmp = tmp->next;
		}
		tmp->next = newList;
	}
}

void	Stack::queue( char c ) {

	++this->_size;
	t_list	*newList = new t_list;
	newList->c = c;
	newList->isChar = true;
	newList->isFixedVal = false;
	newList->next = NULL;
	if (this->lst == NULL)
		this->lst = newList;
	else {

		t_list *tmp = this->lst;
		while ( tmp->next ) {

			tmp = tmp->next;
		}
		tmp->next = newList;
	}
}

void	Stack::pop( void ) {

	if (this->_size + 1> 0) {

		--this->_size;
		t_list *tmp = this->lst;
		this->lst = this->lst->next;
		delete tmp;
	}
}

bool	Stack::empty( void ) const {

	if (this->_size == 0 )
		return true;
	return false;
}

Stack &	Stack::top( void ) {

	return *this;
}

int		Stack::getSize( void ) const {

	return this->_size + 1;
}

std::ostream &	operator<<( std::ostream & o, Stack const & rhs ) {

	if (rhs.lst->isFixedVal)
		o << rhs.lst->fixedVal;
	else if (rhs.lst->isChar)
		o << rhs.lst->c;
	return o;
}
