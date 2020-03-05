#include "Form.hpp"

Form::Form( void ) : _name("unnamed"), _target("undefined"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {

	return;
}

Form::Form( std::string name, std::string target, int gradeToSign, int gradeToExec ) :
		_name(name), _target(target), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	
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

Form::Form( Form const & src ) : _name(src.getName()), _target(src.getTarget()),
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

std::string const &	Form::getTarget( void ) const {

	return this->_target;
}

int		Form::getGradeToSign( void ) const {

	return this->_gradeToSign;
}

int		Form::getGradeToExec( void ) const {

	return this->_gradeToExec;
}

bool	Form::beSigned( Bureaucrat const & b ) {

	if ( b.getGrade() > this->getGradeToSign() ) {

		this->_isSigned = false;
	}
	else {

		this->_isSigned = true;
	}
	return this->_isSigned;
}

void	Form::execute( Bureaucrat const & executor ) const { 

	if ( this->isSigned() == false || executor.getGrade() > this->getGradeToExec() )
		std::cout << executor.getName() << " failed to execute "
			<< this->getName() << " because ";
	if ( this->isSigned() == false )
		throw Form::FormNotSignedException();
	if ( executor.getGrade() > this->getGradeToExec() )
		throw Form::GradeTooLowException();
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

Form::FormNotSignedException::FormNotSignedException( void ) {

	return;
}

Form::FormNotSignedException::FormNotSignedException( Form::FormNotSignedException const & src ){

	*this = src;
}

Form::FormNotSignedException & Form::FormNotSignedException::operator=( Form::FormNotSignedException const & rhs ) {

	static_cast <void> ( rhs );
	return *this;
}

Form::FormNotSignedException::~FormNotSignedException( void ) throw() {

	return;
}

const char*	Form::FormNotSignedException::what( void ) const throw() {

	return "Form is not signed";
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
