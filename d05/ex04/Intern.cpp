#include "Intern.hpp"
#include <stdexcept>

Intern::Intern( void ) {

	return;
}

Intern::Intern( Intern const & src ) {

	*this = src;
}

Intern & Intern::operator=( Intern const & rhs ) {

	if ( this != &rhs ) {

		static_cast <void> ( rhs );
	}
	return *this;
}

Intern::~Intern( void ) {

	return;
}

Form *	Intern::makeForm( std::string const & name, std::string const & target ) {

	Form* newForm = NULL;
	if ( name.empty() || (name != "Shrubbery" && name != "Robotomy" && name != "Presidential") )
		throw Intern::UnknownFormException();
	if ( name == "Shrubbery" )
		newForm = new ShrubberyCreationForm;
	else if ( name == "Robotomy" )
		newForm = new RobotomyRequestForm;
	else
		newForm = new PresidentialPardonForm;
	newForm->setTarget( target );
	std::cout << "Intern creates a " << name << " Form ( s.grade " << newForm->getGradeToSign()
		<< ", ex.grade " << newForm->getGradeToExec() << ") targeted on " << target;
	if ( newForm->isSigned() == true )
		std::cout << " (Signed)" << std::endl;
	else
		std::cout << " (Unsigned)" << std::endl;
	return newForm;
}

Intern::UnknownFormException::UnknownFormException( void ) {

	return;
}

Intern::UnknownFormException::UnknownFormException( UnknownFormException const & src ) {

	*this = src;
}

Intern::UnknownFormException & Intern::UnknownFormException::operator=( UnknownFormException const & rhs ) {

	if ( this != &rhs ) {

		static_cast <void> ( rhs );
	}

	return *this;
}

Intern::UnknownFormException::~UnknownFormException( void ) throw() {

	return;
}

const char*	Intern::UnknownFormException::what( void ) const throw() {

	return "The requested form is not known.";
}
