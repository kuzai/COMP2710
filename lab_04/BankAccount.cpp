#include "BankAccount.h"

#include <iterator>
#include <iostream>

BankAccount::BankAccount() {
	name = "NULL";
}

BankAccount::BankAccount(std::string id, std::string account) {
	name = id;
}

std::string BankAccount::getName() {
	return name;
}

double BankAccount::getBalance(){
	return balance;
}

void BankAccount::withdraw(double amount) {
	balance -= amount;
	transactions.push_back(-amount);
}

void BankAccount::deposit(double amount) {
	balance += amount;
	transactions.push_back(amount);
}

void BankAccount::printTransactions() {
	std::vector<double>::iterator it;
	for(it = transactions.begin(); it != transactions.end(); it++) {
		std::cout << *it << std::endl;	
	}
}

double BankAccount::computeBankBalance() {

}

std::string BankAccount::getAccountType() {
	return accountType;
}
