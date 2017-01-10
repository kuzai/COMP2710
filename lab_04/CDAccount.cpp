#include "CDAccount.h"


CDAccount::CDAccount(std::string id, double ir, std::string account) {
	name = id;
	interestRate = ir;
	accountType = account;
}

void CDAccount::withdraw(double amount) {
	double temp = amount;
	temp += 0.25 * interestRate;
	balance -= temp;
	transactions.push_back(-temp);
}

std::string CDAccount::getAccountType() {
	return accountType;
}
