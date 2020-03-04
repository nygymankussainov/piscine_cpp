#include "Form.hpp"

Form::Form( void ) : _name("unnamed"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {

	return;
}

Form::Form( std::string name, int gradeToSign, int gradeToExec ) :
		_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	
	try {
		if ( this->getGradeToSign() < 1 || this->getGradeToExec() < 0 )
			throw Form::GradeTooHighException();
		else if ( this->getGradeToSign() > 150 || this->getGradeToExec() > 150 )
			throw Form::GradeTooLowException();
	}
	catch ( std::exception & e ) {

		std::cerr << e.what() << std::endl;
		exit(0);
	}
	return;
}

Form::Form( Form const & src ) : _name(src.getName()),
			_isSigned(src.isSigned()), _gradeToSign(src.getGradeToSign()),
			_gradeToExec(src.getGradeToExec()) {

	*this = src;
}

Form &	Form::operator=( Form const & rhs ) {

	if ( this != &rhs ) {

		this->_isSigned = rhs.isSigned();
	}

	return *this;
}

Form::~Form( void ) {

	return;
}

bool	Form::isSigned( void ) const {

	return this->_isSigned;
}

std::string const &	Form::getName( void ) const {

	return this->_name;
}

int		Form::getGradeToSign( void ) const {

	return this->_gradeToSign;
}

int		Form::getGradeToExec( void ) const {

	return this->_gradeToExec;
}

bool	Form::beSigned( Bureaucrat const & b ) {

	try {

		if ( b.getGrade() > this->getGradeToSign() )
			throw Form::GradeTooLowException();
		this->_isSigned = true;
		return true;
	}
	catch ( std::exception & e ) {

		this->_isSigned = false;
		std::cerr << e.what() << std::endl;
		return false;
	}
}

Form::GradeTooHighException::GradeTooHighException( void ) {

	return;
}

Form::GradeTooHighException::GradeTooHighException( Form::GradeTooHighException const & src ) {

	*this = src;
}

Form::GradeTooHighException &	Form::GradeTooHighException::operator=( Form::GradeTooHighException const & rhs ) {

	static_cast <void>( rhs );
	return *this;
}

Form::GradeTooHighException::~GradeTooHighException( void ) throw() {
	
	return;
}

const char*	Form::GradeTooHighException::what( void ) const throw() {

	return "Grade is too high";
}

Form::GradeTooLowException::GradeTooLowException( void ) {

	return;
}

Form::GradeTooLowException::GradeTooLowException( Form::GradeTooLowException const & src ) {

	*this = src;
}

Form::GradeTooLowException &	Form::GradeTooLowException::operator=( Form::GradeTooLowException const & rhs ) {

	static_cast <void>( rhs );
	return *this;
}

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {
	
	return;
}

const char*	Form::GradeTooLowException::what( void ) const throw() {

	return "Grade is too low";
}

std::ostream &	operator<<( std::ostream & o, Form const & rhs ) {

	o << "Form " << rhs.getName();
	if ( rhs.isSigned() )
		o << " (signed)";
	else
		o << " (unsignded)";	
	o << " has " << rhs.getGradeToSign() << " grade to sign and "
		<< rhs.getGradeToExec() << " grade to execute"
		<< std::endl;
	return o;
}
