#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock( void ) {

	this->_intern = NULL;
	this->_signer = NULL;
	this->_executor = NULL;
	return;
}

OfficeBlock::OfficeBlock( Intern & intern, Bureaucrat & signer, Bureaucrat & executor ) {

	this->_intern = &intern;
	this->_signer = &signer;
	this->_signer->setSigner();
	this->_executor = &executor;
	this->_executor->setExecutor();
	return;
}

OfficeBlock::~OfficeBlock( void ) {

	return;
}

Intern *	OfficeBlock::getIntern( void ) const {

	return this->_intern;
}

Bureaucrat * OfficeBlock::getSigner( void ) const {

	return this->_signer;
}

Bureaucrat * OfficeBlock::getExecutor( void ) const {

	return this->_executor;
}

void	OfficeBlock::setIntern( Intern & intern ) {

	this->_intern = &intern;
}

void	OfficeBlock::setSigner( Bureaucrat & signer ) {

	this->_signer = &signer;
	this->_signer->setSigner();
}

void	OfficeBlock::setExecutor( Bureaucrat & executor ) {

	this->_executor = &executor;
	this->_executor->setExecutor();
}

void	OfficeBlock::doBureaucraccy( std::string const & name, std::string const & target ) {

	try {

		if ( this->getIntern() == NULL )
			throw OfficeBlock::NoInternException();
		Form* form = this->getIntern()->makeForm( name, target );
		if ( form == NULL )
			throw "";
		if ( this->getSigner() == NULL )
			throw OfficeBlock::NoSignerException();
		this->getSigner()->signForm( *form );
		if ( this->getExecutor() == NULL )
			throw OfficeBlock::NoExecutorException();
		this->getExecutor()->executeForm( *form );
		delete form;
	}
	catch ( std::exception & e ) {

		std::cerr << e.what() << std::endl;
	}
	catch ( ... ) {

		return;
	}
	std::cout << "That'll do, " << target << ". That'll do ..." << std::endl;
}

OfficeBlock::NoInternException::NoInternException( void ) {
	
	return;
}

OfficeBlock::NoInternException::NoInternException( NoInternException const & src ) {

	*this = src;
}

OfficeBlock::NoInternException & OfficeBlock::NoInternException::operator=( NoInternException const & rhs ) {

	static_cast <void> ( rhs );
	return *this;
}

OfficeBlock::NoInternException::~NoInternException( void ) throw() {

	return;
}

const char*	OfficeBlock::NoInternException::what( void ) const throw() {

	return "No intern found";
}

OfficeBlock::NoSignerException::NoSignerException( void ) {
	
	return;
}

OfficeBlock::NoSignerException::NoSignerException( NoSignerException const & src ) {

	*this = src;
}

OfficeBlock::NoSignerException & OfficeBlock::NoSignerException::operator=( NoSignerException const & rhs ) {

	static_cast <void> ( rhs );
	return *this;
}

OfficeBlock::NoSignerException::~NoSignerException( void ) throw() {

	return;
}

const char*	OfficeBlock::NoSignerException::what( void ) const throw() {

	return "No signer bureaucrat found";
}

OfficeBlock::NoExecutorException::NoExecutorException( void ) {
	
	return;
}

OfficeBlock::NoExecutorException::NoExecutorException( NoExecutorException const & src ) {

	*this = src;
}

OfficeBlock::NoExecutorException & OfficeBlock::NoExecutorException::operator=( NoExecutorException const & rhs ) {

	static_cast <void> ( rhs );
	return *this;
}

OfficeBlock::NoExecutorException::~NoExecutorException( void ) throw() {

	return;
}

const char*	OfficeBlock::NoExecutorException::what( void ) const throw() {

	return "No executor bureaucrat found";
}
