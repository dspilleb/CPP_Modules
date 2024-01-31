/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:37:48 by dspilleb          #+#    #+#             */
/*   Updated: 2024/01/31 11:49:02 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <ctime>
#include <iostream>
#include <sstream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount (initial_deposit), _nbDeposits(0), _nbWithdrawals (0)
{
	this->_accountIndex = _nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";created" << std::endl;
}

Account::Account() : _amount (0), _nbDeposits(0), _nbWithdrawals (0)
{
	return;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";closed" << std::endl;
	return;
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
void	Account::makeDeposit( int deposit )
{
	int p_amount = this->checkAmount();
	_totalAmount += deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << p_amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = this->checkAmount();
	_displayTimestamp();
	if (p_amount - withdrawal >= 0)
	{
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << " index:" << this->_accountIndex;
		std::cout << ";p_amount:" << p_amount;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << this->checkAmount();
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount();
	std::cout << ";withdrawal:refused" << std::endl;
	return false;
}
int		Account::checkAmount( void ) const
{
	return this->_amount;
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	//Testing
	// std::cout << "[19920104_091532]";
    std::time_t currentTime = std::time(NULL);
    std::tm* timeinfo = std::localtime(&currentTime);
    std::stringstream ss;

    ss << std::setw(4) << std::setfill('0') << timeinfo->tm_year + 1900;
    ss << std::setw(2) << std::setfill('0') << timeinfo->tm_mon + 1;
    ss << std::setw(2) << std::setfill('0') << timeinfo->tm_mday;

    ss << "_";
    ss << std::setw(2) << std::setfill('0') << timeinfo->tm_hour;
    ss << std::setw(2) << std::setfill('0') << timeinfo->tm_min;
    ss << std::setw(2) << std::setfill('0') << timeinfo->tm_sec;
	std::cout << ss.str();
}
