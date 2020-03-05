#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iomanip>

const int ShrubberyCreationForm::_gradeToSign = 145;
const int ShrubberyCreationForm::_gradeToExec = 137;

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	Form("Shrubbery", "undefined", ShrubberyCreationForm::_gradeToSign, ShrubberyCreationForm::_gradeToExec) {

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) :
	Form( "Shrubbery", target, ShrubberyCreationForm::_gradeToSign, ShrubberyCreationForm::_gradeToExec ) {

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : Form( src ) {

	return;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {

	if ( this != &rhs ) {

		Form::operator=( rhs );
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

	return;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {

	Form::execute( executor );	
	std::ofstream file;
	try {

		file.open( this->getTarget() );
		if ( !file.is_open())
			throw "Couldn't open a file";
	}
	catch ( std::string s ) {

		std::cerr << s << std::endl;
	}
	file << std::setw(10) << 1 << std::endl;
	file << std::setw(9) << '/' << std::setw(2) << '\\' << std::endl;
	file << std::setw(8) << 2 << std::setw(4) << 2 << std::endl;
	file << std::setw(7) << '/' << std::setw(6) << '\\' << std::endl;
	file << std::setw(6) << 3 << std::setw(8) << 3 << std::endl;
	file << std::setw(5) << '/' << std::setw(10) << '\\' << std::endl;
	file << std::setw(4) << std::setfill(' ') << ' ';
	file << std::setw(11) << std::setfill('-') << '-' << std::endl;
	file << std::setw(9) << std::setfill(' ') << ' ' << '#' << std::endl;
}
