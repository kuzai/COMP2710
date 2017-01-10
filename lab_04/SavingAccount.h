#ifndef SAVINGH
#define SAVINGH

#include "BankAccount.h"
#include <string>

class SavingAccount : public BankAccount {
	public:
		SavingAccount(std::string id, std::string account);
		std::string getAccountType();
};

#endif
