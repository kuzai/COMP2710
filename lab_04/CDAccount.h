#ifndef CDACCOUNTH
#define CDACCOUNTH

#include "BankAccount.h"

class CDAccount : public BankAccount {
	public:
		CDAccount(std::string id, double ir, std::string account);
		void withdraw(double amount);
		std::string getAccountType();
	private:
		double interestRate;
};

#endif
