#include "SavingAccount.h"

SavingAccount::SavingAccount(std::string id, std::string account) {
	name = id;
	accountType = account;
}

std::string SavingAccount::getAccountType() {
	return accountType;
}
