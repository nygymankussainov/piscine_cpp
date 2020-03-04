#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string const & name ) {

	this->_name = name;
	this->_grade = 150;
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) {

	*this = src;
}

Bureaucrat::~Bureaucrat( void ) {

	return;
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs ) {

	if ( this != &rhs ) {

		this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::string const &	Bureaucrat::getName( void ) const {

	return this->_name;
}

int				Bureaucrat::getGrade( void ) const {

	return this->_grade;
}

void		Bureaucrat::setGrade( int amount ) {

	if ( amount > 150 ) {

		throw Bureaucrat::GradeTooLowException();
	}
	else if ( amount < 1 ) {

		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade = amount;
}

Bureaucrat::GradeTooHighException::GradeTooHighException( void ) {

	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException( Bureaucrat::GradeTooHighException const & src ) {

	*this = src;
}

Bureaucrat::GradeTooHighException &	Bureaucrat::GradeTooHighException::operator=( Bureaucrat::GradeTooHighException const & rhs ) {

	static_cast <void> ( rhs );
	return *this;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {

	return;
}

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw() {

	return "Grade is too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException( void ) {

	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException( Bureaucrat::GradeTooLowException const & src ) {

	*this = src;
}

Bureaucrat::GradeTooLowException &	Bureaucrat::GradeTooLowException::operator=( Bureaucrat::GradeTooLowException const & rhs ) {

	static_cast <void> ( rhs );
	return *this;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {

	return;
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw() {

	return "Grade is too low";
}

void	Bureaucrat::incrementGrade( void ) {

	if ( this->getGrade() - 1 < 1 ) {

		throw Bureaucrat::GradeTooHighException();
	}
	--this->_grade;
}

void	Bureaucrat::decrementGrade( void ) {

	if ( this->getGrade() + 1 > 150 ) {

		throw Bureaucrat::GradeTooLowException();
	} 
	++this->_grade;
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs ) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade()
		<< std::endl;
	return o;
}
