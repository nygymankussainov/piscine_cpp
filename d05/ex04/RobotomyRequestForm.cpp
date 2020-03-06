#include "RobotomyRequestForm.hpp"

const int RobotomyRequestForm::_gradeToSign = 72;
const int RobotomyRequestForm::_gradeToExec = 45;

RobotomyRequestForm::RobotomyRequestForm( void ) :
	Form("Robotomy", "undefined", RobotomyRequestForm::_gradeToSign, RobotomyRequestForm::_gradeToExec) {

	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) :
	Form("Robotomy", target, RobotomyRequestForm::_gradeToSign, RobotomyRequestForm::_gradeToExec) {

	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form( src ) {

	return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {

	if ( this != &rhs ) {

		Form::operator=( rhs );
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	
	return;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {

	Form::execute( executor );
	if ( rand() & 1 ) {

		std::cout << "Bzzzz..." << this->getTarget() << " has been robotomized"
			<< " successfully 50% of the time." << std::endl;
	}
	else
	{
		std::cout << this->getTarget() << " robotomazation has failed!" << std::endl;
	}
}
