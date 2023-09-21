#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
Account::Account( int initial_deposit )
{
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex <<";amount:"<<_amount<<";created" << std::endl;
}
Account::~Account( void )
{
	_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"<< _amount << ";closed" << std::endl;
}
void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
Account::Account( void )
{
	_totalAmount += 0;
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:"<< deposit << ";amount:"<< _amount + deposit << ";nb_deposits:"<< ++_nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal: " << withdrawal << ";amount: " << _amount - withdrawal << ";nb_withdrawals: " << ++_nbWithdrawals << std::endl;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"<< _amount << ";deposits:"<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::cout << "[" << std::time(0) << "] ";
}


