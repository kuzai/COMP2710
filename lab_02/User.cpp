#include "User.h"
#include <iostream>


//simply initialize values
/*User::User(){
	username;
	friendList;
	hashList;
}*/

//construct and assign name
User::User(std::string name, FileHandler fh){
	username = name;
	fHandler = fh;
	//friendList;
}

//check if user is friends already
bool User::checkFriends(std::string name) {
	for(std::vector<User>::iterator it = friendList.begin(); it != friendList.end(); it++)
	{
		if (name == (*it).getUsername())
			return true;
	}
	return false;
}

//return list of friends
std::vector<User> User::getFriends() {
	return friendList;
}


//this function assumes that a check has already been done for if the user exists
//add a friend for a user
bool User::addFriend(User user) {
	friendList.push_back(user);
	return true;
}
//deprecated
bool User::postMessage(std::string message) {
	return true;
}
//return current username
std::string User::getUsername() {
	return username;
}
//add a hash to follow
bool User::addHash(std::string hash) {
	hashList.push_back(hash);
	updateHash(hash);
	return true;
}

bool User::findHash(std::string hash) {
		
	for(std::vector<std::string>::iterator it = hashList.begin(); it != hashList.end(); it++)
	{
		//std::cout << *it << "from the function call" << std::endl;
		if (hash == *it)
			return true;
	}
	return false;
}


bool User::updateHash(std::string hash) {
	ofstream outStream;
	outStream.open(username + "_tags.txt", std::ofstream::app);
	outStream << hash << std::endl;
	return true;
}








