#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
#include "FileHandler.h"
//#include "System.h"

class User 
{
	private:
		std::string username;
		FileHandler fHandler;
		std::vector<std::string> friendList;
		
		//void friendListManager();
	public:
		User();		
		User(std::string name);
		bool checkFriends(std::string name);
		std::vector<User> getFriends();
		bool addFriend(std::string user);
		std::string getUsername();
		bool addHash(std::string hash);
		bool findHash(std::string hash);
		bool updateHash(std::string hash);
		std::vector<std::string> hashList;	
};
#endif
