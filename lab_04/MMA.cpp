#include "MMA.h"

MMA::MMA(std::string id, std::string account) {
	name = id;
	accountType = account;
}

void MMA::withdraw(double amount) {
	double temp = amount;
	if(withdrawals > 2)
		temp += 1.5;
	balance -= temp;
	withdrawals++;
	transactions.push_back(-temp);
}

std::string MMA::getAccountType() {
	return accountType;
}


