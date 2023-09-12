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
	std::cout << "\033[33m index:\033[32m" << _accountIndex << "\033[33m;amount:\033[32m" 
				<< _amount << "\033[33m;created\033[0m" << std::endl;
}

Account::~Account( void) {
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout << "\033[33m index:\033[32m" << _accountIndex << "\033[33m;amount:\033[32m" 
				<< _amount << "\033[33m;closed\033[0m" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_totalAmount -= _amount;
	_amount += deposit;
	_totalAmount += _amount;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "\033[33m index:\033[32m" << _accountIndex << "\033[33m;p_amount:\033[32m" 
				<< _amount - deposit << "\033[33m;deposit:\033[32m" << deposit 
				<< "\033[33m;amount:\033[32m" << _amount << "\033[33m;nb_deposits:\033[32m" 
				<< _nbDeposits << "\033[0m" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "\033[33m index:\033[32m" << _accountIndex << "\033[33m;p_amount:\033[32m" 
				<< _amount << "\033[33m;withdrawal:" << "refused\033[0m" << std::endl;
		return (0);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "\033[33m index:\033[32m" << _accountIndex << "\033[33m;p_amount:\033[32m" 
				<< _amount + withdrawal << "\033[33m;withdrawal:\033[32m" << withdrawal 
				<< "\033[33m;amount:\033[32m" << _amount << "\033[33m;nb_withdrawals:\033[32m" 
				<< _nbWithdrawals << "\033[0m" << std::endl;
	return (1);
}
int		Account::checkAmount( void ) const {
	return (_amount);
}
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "\033[33m index:\033[32m" << _accountIndex << "\033[33m;amount:\033[32m" << _amount << "\033[33m;deposits:\033[32m"
				<< _nbDeposits << "\033[33m;withdrawals:\033[32m" << _nbWithdrawals << "\033[0m" << std::endl;
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
	std::cout << "\033[33m accounts:\033[32m" << _nbAccounts << "\033[33m;total:\033[32m" << _totalAmount << "\033[33m;deposits:\033[32m"
				<< _totalNbDeposits << "\033[33m;withdrawals:\033[32m" << _totalNbWithdrawals << "\033[0m" << std::endl;
}

// Private

void	Account::_displayTimestamp( void ) {
	std::time_t t = std::time(NULL);
    std::tm tm = *std::localtime(&t);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", &tm);
	std::cout << "\033[34m" << buffer << "\033[0m";
}