#ifndef CHECKH
#define CHECKH

#include <string>
#include "BankAccount.h"

class CheckingAccount : public BankAccount { 
	public:
		CheckingAccount(std::string id, std::string account);
		void withdraw(double amount);
		std::string getAccountType();
};
#endif
