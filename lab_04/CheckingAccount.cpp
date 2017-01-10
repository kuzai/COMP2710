#include "CheckingAccount.h"


CheckingAccount::CheckingAccount(std::string id, std::string account){
	name = id;
	accountType = account;
}

void CheckingAccount::withdraw(double amount){
	double temp = amount;
	if(balance < 500)
		temp += 2.5;
	balance -= temp;
	transactions.push_back(-temp);
}

std::string CheckingAccount::getAccountType() {
	return accountType;
}
