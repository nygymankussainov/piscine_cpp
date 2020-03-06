#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ) {

	this->_name = "unnammed";
	this->_grade = 150;
	this->_signer = false;
	this->_executor = false;
	return;
}

Bureaucrat::Bureaucrat( std::string const & name, int grade ) {

	this->_name = name;
	this->_grade = grade;
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

bool	Bureaucrat::isSigner( void ) const {

	if ( this->_signer == true )
		return true;
	return false;
}

bool	Bureaucrat::isExecutor( void ) const {

	if ( this->_executor == true )
		return true;
	return false;
}

void	Bureaucrat::setSigner( void ) {

	this->_signer = true;
	this->_executor = false;
}

void	Bureaucrat::setExecutor( void ) {

	this->_executor = true;
	this->_signer = false;
}

void		Bureaucrat::setGrade( int amount ) {

	try {
		if ( amount > 150 ) {

			throw Bureaucrat::GradeTooLowException();
		}
		else if ( amount < 1 ) {

			throw Bureaucrat::GradeTooHighException();
		}
		this->_grade = amount;
	}
	catch ( std::exception & e ) {

		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::incrementGrade( void ) {

	try {
		if ( this->getGrade() - 1 < 1 ) {

			throw Bureaucrat::GradeTooHighException();
		}
		--this->_grade;
	}
	catch ( std::exception & e ) {

		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade( void ) {

	try {
		if ( this->getGrade() + 1 > 150 ) {

			throw Bureaucrat::GradeTooLowException();
		} 
		++this->_grade;
	}
	catch ( std::exception & e ) {

		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm( Form & f ) {

	try {

		if ( f.beSigned(*this) == false ) {

			std::cout << this->getName() << " cannot sign " << f.getName()
				<< " because ";
			throw Form::GradeTooLowException();
		}
		std::cout << "Bureaucrat " << this->getName() << " (Grade "
			<< this->getGrade() << ") signs a " << f.getName()
			<< " Form (s.grade " << f.getGradeToSign() << ", ex.grade "
			<< f.getGradeToExec() << ") targeted on " << f.getTarget()
			<< " (";
		if ( f.isSigned() == true )
			std::cout << "Unsigned)" << std::endl;
		else
			std::cout << "Signed)" << std::endl;
	}
	catch ( std::exception & e ) {

		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( Form const & form ) {

	try {

		form.execute( *this );
		std::cout << "Bureaucrat " << this->getName() << " (Grade "
			<< this->getGrade() << ") executes a " << form.getName()
			<< " Form (s.grade " << form.getGradeToSign() << ", ex.grade "
			<< form.getGradeToExec() << ") targeted on " << form.getTarget()
			<< " (";
		if ( form.isSigned() == true )
			std::cout << "Signed)" << std::endl;
		else
			std::cout << "Unsigned)" << std::endl;
	}
	catch ( std::exception & e ) {

		std::cout << e.what() << std::endl;
	}
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

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs ) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade()
		<< std::endl;
	return o;
}
