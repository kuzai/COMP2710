#ifndef BANK_ACCOUNTH
#define BANK_ACCOUNTH

#include <string>
#include <vector>

class BankAccount{
	public:
		BankAccount();
		BankAccount(std::string id, std::string account);
		std::string getName();
		double getBalance();
		virtual void withdraw(double amount);
		void deposit(double amount);
		virtual void printTransactions();
		virtual double computeBankBalance();
		virtual std::string getAccountType();
	private:
	protected:
		std::string name;
		double balance;
		std::vector<double> transactions;
		std::string accountType;
		

};

#endif
