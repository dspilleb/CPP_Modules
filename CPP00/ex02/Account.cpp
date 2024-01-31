/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:37:48 by dspilleb          #+#    #+#             */
/*   Updated: 2024/01/31 10:46:46 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount (initial_deposit), _nbDeposits(0), _nbWithdrawals (0)
{
	this->_accountIndex = _nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" + int_to_string(this->_accountIndex);
	std::cout << ";amount:" + int_to_string(this->checkAmount());
	std::cout << ";created" << std::endl;
}

Account::Account() : _amount (0), _nbDeposits(0), _nbWithdrawals (0)
{
	return;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" + int_to_string(this->_accountIndex);
	std::cout << ";amount:" + int_to_string(this->checkAmount());
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
	std::cout << " accounts:" + int_to_string(getNbAccounts());
	std::cout << ";total:" + int_to_string(getTotalAmount());
	std::cout << ";deposits:" + int_to_string(getNbDeposits());
	std::cout << ";withdrawals:" + int_to_string(getNbWithdrawals()) << std::endl;
}
void	Account::makeDeposit( int deposit )
{
	int p_amount = this->checkAmount();
	_totalAmount += deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" + int_to_string(this->_accountIndex);
	std::cout << ";p_amount:" + int_to_string(p_amount);
	std::cout << ";deposit:" + int_to_string(deposit);
	std::cout << ";amount:" + int_to_string(this->checkAmount());
	std::cout << ";nb_deposits:" + int_to_string(this->_nbDeposits) << std::endl;
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
		std::cout << " index:" + int_to_string(this->_accountIndex);
		std::cout << ";p_amount:" + int_to_string(p_amount);
		std::cout << ";withdrawal:" + int_to_string(withdrawal);
		std::cout << ";amount:" + int_to_string(this->checkAmount());
		std::cout << ";nb_withdrawals:" + int_to_string(_nbWithdrawals) << std::endl;
		return true;
	}
	std::cout << " index:" + int_to_string(this->_accountIndex);
	std::cout << ";p_amount:" + int_to_string(this->checkAmount());
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
	std::cout << " index:" + int_to_string(this->_accountIndex);
	std::cout << ";amount:" + int_to_string(this->checkAmount());
	std::cout << ";deposits:" + int_to_string(_nbDeposits);
	std::cout << ";withdrawals:" + int_to_string(_nbWithdrawals) << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::cout << "[";
	std::cout << "19920104";
	std::cout << "_";
	std::cout << "091532";
	std::cout << "]";
}

std::string Account::int_to_string(const int val)
{
	std::stringstream ss;
	ss << val;
	return (ss.str());
}