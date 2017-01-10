#ifndef MMAH
#define MMAH

#include "BankAccount.h"
#include <string>

class MMA : public BankAccount {
	public:
		MMA(std::string id, std::string account);
		void withdraw(double amount);
		std::string getAccountType();
	private:
		int withdrawals;
};
#endif
