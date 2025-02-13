#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" 
				<< _amount << ";created" << std::endl;
}

Account::~Account( void) {
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" 
				<< _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_totalAmount -= _amount;
	_amount += deposit;
	_totalAmount += _amount;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" 
				<< _amount - deposit << ";deposit:" << deposit 
				<< ";amount:" << _amount << ";nb_deposits:" 
				<< _nbDeposits << "" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" 
				<< _amount << ";withdrawal:" << "refused" << std::endl;
		return (0);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" 
				<< _amount + withdrawal << ";withdrawal:" << withdrawal 
				<< ";amount:" << _amount << ";nb_withdrawals:" 
				<< _nbWithdrawals << "" << std::endl;
	return (1);
}
int		Account::checkAmount( void ) const {
	return (_amount);
}
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
				<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << "" << std::endl;
}

// Static

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
				<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "" << std::endl;
}

// Private

void	Account::_displayTimestamp( void ) {
	std::time_t t = std::time(NULL);
    std::tm tm = *std::localtime(&t);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", &tm);
	std::cout << buffer << "";
}