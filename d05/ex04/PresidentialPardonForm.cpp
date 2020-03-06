#include "PresidentialPardonForm.hpp"

const int PresidentialPardonForm::_gradeToSign = 25;
const int PresidentialPardonForm::_gradeToExec = 5;

PresidentialPardonForm::PresidentialPardonForm( void ) :
	Form("Presidential", "undefined", PresidentialPardonForm::_gradeToSign, PresidentialPardonForm::_gradeToExec) {

	return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) :
	Form("Presidential", target, PresidentialPardonForm::_gradeToSign, PresidentialPardonForm::_gradeToExec) {

	return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : Form( src ) {

	return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {

	if ( this != &rhs ) {

		Form::operator=( rhs );
	}

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

	return;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {

	Form::execute( executor );
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox."
		<< std::endl;
}
