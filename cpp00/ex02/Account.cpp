	#include "Account.hpp"
    #include <iostream>
    #include <iomanip>

    int Account::_nbAccounts = 0;
    int Account::_totalAmount = 0;
    int Account::_totalNbDeposits = 0;
    int Account::_totalNbWithdrawals = 0;
    
    Account::Account( int initial_deposit )
    {
        this->_accountIndex = this->getNbAccounts();
        this->_amount = initial_deposit;
        this->_nbDeposits = 0;
        this->_nbWithdrawals = 0;
        this->_nbAccounts++;
        this->_totalAmount += this->_amount;
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";amount:" << \
        this->_amount << ";created" << std::endl;
    }

	Account::~Account( void )
    {
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";amount:" << \
        this->_amount << ";closed" << std::endl;
        this->_nbAccounts--;
        this->_totalAmount -= this->_amount;
        this->_totalNbDeposits -= this->_nbDeposits;
        this->_totalNbWithdrawals -= this->_nbWithdrawals;
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
        std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << \
        ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals \
        << std::endl;
    }

    void	Account::makeDeposit( int deposit )
    {
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
        this->_amount += deposit;
        this->_totalAmount += deposit;
        this->_nbDeposits++;
        this->_totalNbDeposits++;
        std::cout << ";deposit:" << deposit << ";amount:" << this->_amount << \
        ";nb_deposits:" << this->_nbDeposits << std::endl;
    }

	bool	Account::makeWithdrawal( int withdrawal )
    {
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << \
        ";withdrawal:";
        if (this->_amount < withdrawal)
        {
            std::cout << "refused" << std::endl;
            return 1;
        }
        this->_amount -= withdrawal;
        this->_totalAmount -= withdrawal;
        this->_nbWithdrawals++;
        this->_totalNbWithdrawals++;
        std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << \
        this->_nbWithdrawals << std::endl;
        return 0;
    }

	int		Account::checkAmount( void ) const
    {
        return this->_amount;
    }

	void	Account::displayStatus( void ) const
    {
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << \
        ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << \
        std::endl;
    }

    void	Account::_displayTimestamp( void )
    {
        time_t temp;
        struct tm *timeinfo;

        time(&temp);
        timeinfo = localtime(&temp);
        if (timeinfo->tm_sec > 59)
            timeinfo->tm_sec = 59;
        std::cout << "[" << 1900 + timeinfo->tm_year;
        std::cout << std::setw(2) << std::setfill('0') << 1 + timeinfo->tm_mon;
        std::cout << std::setw(2) << timeinfo->tm_mday;
        std::cout << "_";
        std::cout << std::setw(2) << timeinfo->tm_hour;
        std::cout << std::setw(2) << timeinfo->tm_min;
        std::cout << std::setw(2) << timeinfo->tm_sec;
        std::cout << "] ";
    }