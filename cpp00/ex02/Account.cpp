#include "Account.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// initialize static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// initialize helper functions
Account::Account(void){}
int Account::checkAmount(void) const {return _amount;}
int Account::getNbAccounts(void) {return _nbAccounts;}
int Account::getTotalAmount(void) {return _totalAmount;}
int Account::getNbDeposits(void) {return _totalNbDeposits; }
int Account::getNbWithdrawals(void) {return _totalNbWithdrawals;}
void Account::_displayTimestamp(void) {std::cout << "[19920104_091532] ";}

// displayStatus will display the account status
void Account::displayStatus(void) const 
{
    _displayTimestamp();
    std::cout <<YELLOW "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << RESET << std::endl;
}

// displayAccountsInfos will display all the accounts informations
void Account::displayAccountsInfos(void) 
{
    _displayTimestamp();
    std::cout <<BLUE "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << RESET << std::endl;
}

// initialize class destructor
Account::~Account(void) 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// initialize class constructor
Account::Account(int initial_deposit) 
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// makeDeposit will add the deposit to the account
void Account::makeDeposit(int deposit) 
{
    _displayTimestamp();
    std::cout <<GREEN "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << RESET << std::endl;
}

// makeWithdrawal will subtract the withdrawal from the account
bool Account::makeWithdrawal(int withdrawal) 
{
    _displayTimestamp();
    std::cout <<RED "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    if (withdrawal > _amount) 
    {
        std::cout << "refused" << RESET << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << RESET << std::endl;
    return true;
}
