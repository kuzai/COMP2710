#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
//#include "System.h"

class User 
{
	private:
		std::string username;
		std::vector<User> friendList;
		std::vector<std::string> hashList;
		//void friendListManager();
	public:
		User();		
		User(std::string name);
		bool checkFriends(std::string name);
		std::vector<User> getFriends();
		bool addFriend(User user);
		bool postMessage(std::string message);
		std::string getUsername();
		bool addHash(std::string hash);
		bool findHash(std::string hash);	
};
#endif
