#include <vector>
#include <string>
#include <iostream>
#include "BankAccount.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "MMA.h"
#include "CDAccount.h"

std::vector<BankAccount> activeUsers;

BankAccount* findAccount(std::string name, std::string acct);
void setAccount(std::string id, std::string acct);
void cinFlush() {
	std::string trash;
	std::getline(std::cin, trash);
}

BankAccount* b;
bool quit = false;
int main() {
	while(1) {
		if(quit)
			break;
		std::cout << "--------------------------" << std::endl;
		std::cout << "\t Welcome to Aubie Bank!" << std::endl;
		std::cout << "--------------------------" << std::endl;
		std::cout << "Enter an option: (1) Create Account, (2) Deposit, (3) Withdraw";
		std::cout << ", (4) Transfer fund, (5) Inquiry, (6) Print All,";
		std::cout << ", (7) Print Bank Balance, (8) Quit: ";
		int option;
		double amount;
		double tot;
		std::vector<BankAccount>::iterator it;
		std::string account = "";
		std::string name = "";
		std::cin >> option;
		cinFlush();
		switch(option) {
			case 1:
				std::cout << "Enter name: ";
				std::getline(std::cin, name);
				std::cout << std::endl;
				std::cout << "Enter account type (c, s, m, cd): ";
				std::getline(std::cin, account);
				if(account == "cd") {
					std::cout << std::endl;
					std::cout << "Enter interest: ";
					double inter;
					std::cin >> inter;
					cinFlush();
					std::cout << std::endl;
					activeUsers.push_back(CDAccount(name, inter, account));
				}
				if(account == "c")
					activeUsers.push_back(CheckingAccount(name, account));
				if(account == "s")
					activeUsers.push_back(SavingAccount(name, account));
				if(account == "m")
					activeUsers.push_back(MMA(name, account));
				
				break;
			case 2:
				std::cout << "Enter name: ";
				std::getline(std::cin, name);
				std::cout << std::endl;
				std::cout << "Enter account type (c, s, m, cd): ";
				std::getline(std::cin, account);
				setAccount(name, account);
				//BankAccount* b = findAccount(name, account);
				if(b == NULL)
					std::cout << "No such account" << std::endl;
				std::cout << "Enter deposit amount: ";
				//double amount;
				std::cin >> amount;
				cinFlush();
				b->deposit(amount);
				break;
			case 3:
				std::cout << "Enter name: ";
				std::getline(std::cin, name);
				std::cout << std::endl;
				std::cout << "Enter account type (c, s, m, cd): ";
				std::getline(std::cin, account);
				setAccount(name, account);
				//BankAccount* b = findAccount(name, account);
				if(b == NULL)
					std::cout << "No such account" << std::endl;
				std::cout << "Enter deposit amount: ";
				//double amount;
				std::cin >> amount;
				cinFlush();
				b->withdraw(amount);
				break;
			case 4:
				break;
			case 5:
				std::cout << "Enter name: ";
				std::getline(std::cin, name);
				std::cout << std::endl;
				std::cout << "Enter account type (c, s, m, cd): ";
				std::getline(std::cin, account);
				setAccount(name, account);
				//BankAccount* b = findAccount(name, account);
				if(b == NULL)
					std::cout << "No such account" << std::endl;
				std::cout << "Current Balance: " << b->getBalance();
				std::cout << std::endl;
				break;
			case 6:
				std::cout << "Enter name: ";
				std::getline(std::cin, name);
				std::cout << std::endl;
				std::cout << "Enter account type (c, s, m, cd): ";
				std::getline(std::cin, account);
				setAccount(name, account);
				//BankAccount* b = findAccount(name, account);
				if(b == NULL)
					std::cout << "No such account" << std::endl;
				b->printTransactions();
				break;
			case 7:
				//double tot;
				for(it = activeUsers.begin(); it != activeUsers.end(); it++) {
					double b = it->getBalance();
					tot += b;
				}
				std::cout << "Total Bank Balance: " << tot;
				break;
			case 8:
				quit = true;
				break;
			default:
				std::cout << "Sorry, invalid option" << std::endl;
				break;
		}
	}

}

BankAccount* findAccount(std::string id, std::string acct) {
	std::vector<BankAccount>::iterator it;
	for(it = activeUsers.begin(); it != activeUsers.end(); it++) {
		BankAccount b = *it;
		std::string n = b.getName();
		std::string t = b.getAccountType();
		if(n == id && t == acct)
			return &(*it);
	}
	return NULL;
}

void setAccount(std::string id, std::string acct) {
	BankAccount* f = findAccount(id, acct);
	b = f;
}


