#include <iostream>
#include "Account.class.hpp"

Account::Account( int initial_deposit ) {

	Account::_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	Account::_amount = 0;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
	Account::makeDeposit(initial_deposit);
	return;

}

Account::~Account( void ) {

	Account::_nbAccounts -= 1;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	return;
}

// Non-member functions: --------------------- //

int		Account::getNbAccounts( void ) {

	return Account::_nbAccounts;
}

int		Account::getTotalAmount( void ) {

	return Account::_totalAmount;
}

int		Account::getNbDeposits( void ) {

	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals( void ) {

	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {

	// finish this method
	return;
}
// --------------------------------------------- //

// Member functions: --------------------------- //

void	Account::makeDeposit( int deposit ) {

	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	if (this->_amount >= withdrawal) {

		this->_amount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
		this->_nbWithdrawals += 1;
		return true;
	}
	return false;
}

int		Account::checkAmount( void ) const {

	return (this->_amount);
}

void	Account::displayStatus( void ) const {

// finish this func
	return;
}

// --------------------------------------------- //

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;
