#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <string>
#include "Menu.h"
#include "User.h"
#include "WallPage.h"
#include "FileHandler.h"
#include <vector>

class System
{
	private:
		bool keepRunning;
		User activeUser;
		std::vector<User> userList;
		std::string buffer;
		Menu menu;
		void handleInput();
		void createUser(std::string name);
		void login(User user);
		bool checkUser(std::string name);
		std::string postMessage();
		std::string append(std::string message, std::string usrbuff);
		std::string append2(std::string message, std::string usrbuff);
		User findUser(std::string name);
		static WallPage wallPage;
		FileHandler fHandler;
		std::string changeTime();
	public:
		System();
		void run();
		void clearBuffer();
		//string[] getUsers() { return userList;}
		//User findUser() {return fUser;}	
};

#endif
