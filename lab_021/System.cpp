#include "System.h"
#include "Menu.h"
#include "WallPage.h"
#include "HomePage.h"
#include <iostream>
#include <fstream>
#include <sstream>

//constructor

System::System(){
	buffer;
	keepRunning = true;
	activeUser;
	userList;
	
}

void System::clearBuffer() {
	std::cin.clear();
	std::cin.ignore(100000, '\n');
}

void System::run()
{
	std::ifstream inStream;
	inStream.open("userList.txt");
	if(inStream.fail()) {
		std::ofstream outStream;
		outStream.open("userList.txt");
		outStream.close();
	}
	inStream.close();

	inStream.open("sysTime");
	if(inStream.fail()) {
		std::ofstream outStream;
		outStream.open("sysTime");
		outStream << "0";
		outStream.close();
	}
	inStream.close();
	
	std::cout << "Welcome to Distributed AubieBook!" << std::endl << "Enter Username: ";
	std::string newUser;
	std::getline(std::cin, newUser);
	createUser(newUser);
	while(1)
	{
		//std::cout << "running";
		//menu.newLogin("Paul");
		if(activeUser.getUsername().empty()) {
			menu.print();
		}
		else menu.print(activeUser.getUsername());
		handleInput();
		if(!keepRunning) {
			break;
		}
		
	}
}

void System::handleInput() {
	WallPage wallPages;
	HomePage homePages(fHandler);
	int val;
	std::string temp;
	std::cin >> val;
	if(std::cin.fail()) {
		std::cout << "Entered value is not a number option" << std::endl;
		clearBuffer();
		return;
	}
	clearBuffer();
	switch(val){
		//post message	
		case 0 :
			//buffer.insert(0, postMessage());
			fHandler.writeUserBuffer(activeUser.getUsername(), postMessage());
			std::cout << buffer << std::endl;
			break;
		//wall
		case 1 : 
			//WallPage wallPages();
			//std::string tBuff;
			temp = fHandler.readUserBuffer(activeUser.getUsername());
			std::cout << temp << std::endl;
			wallPages.updateWall(activeUser, temp, true);
			break;			
			//std::cout << "3" << std::endl;
		//home
		case 2 : 
			homePages.userSort(activeUser);
			break;			
			//std::cout << "4" << std::endl;
		//add friend
		case 3 : 
			std::cout << "Enter friend's name: ";
			std::getline(std::cin, temp);
			if(!checkUser(temp) || activeUser.checkFriends(temp)) {
				std::cout << "User does not exist or is already a friend!"<< std::endl;
				break;
			}
			else activeUser.addFriend(temp);//activeUser.addFriend(findUser(temp));
			break;			
			//std::cout << "5" << std::endl;
		//add hash
		case 4 :
			std::cout << "Enter Hash to follow: ";
			std::getline(std::cin, temp);
			if(activeUser.findHash(temp)) {
				std::cout << "Hash already followed!" << std::endl;
				break;
			}
			else activeUser.addHash(temp);
			break;
		//quit
		case 5 : 
			keepRunning = false;
			break;
		default:
			std::cout << "Not a valid numerical option" << std::endl;	
	
	}
}

void System::createUser(std::string name) {
	if(checkUser(name))
	{
		User user(name);
		login(user);	
	}
	else {
	User user(name);
	userList.push_back(user);
	login(user);
	menu.newLogin(user.getUsername());
	fHandler.createUser(name);
	std::ofstream oStream;
	oStream.open("userList.txt", std::ofstream::app);
	oStream << name << std::endl;
	oStream.close();
	//std::cout << "hey I ran!!" + user.getUsername() << std::endl; 
	}
}


void System::login(User user) {
	activeUser = user;
}

//Try to open the user file, if it isn't there then the user doesn't exist
bool System::checkUser(std::string name) {
	std::ifstream inStream;
	inStream.open(name + ".txt");
	if(inStream.fail()) {
		inStream.close();
		return false;
	}
	return true;
}

std::string System::postMessage() {
	bool recInput = true;
	bool firstLine = true;
	std::string usrMsg;
	std::string usrBuf;
	std::cout << "Enter Message: " << std::endl;
	while(recInput) {
		std::getline(std::cin, usrMsg);
		if(usrMsg == "$$") {
			recInput = false;
			break;
		}
		if(firstLine) {
			usrBuf = append(usrMsg, usrBuf);
			firstLine = false;
		}		
		else {
			usrBuf = append2(usrMsg, usrBuf);
		}
	}
	return usrBuf;
}

std::string System::append(std::string message, std::string usrbuff)
{
	std::cout << "debug 2";
	usrbuff += "%[" + changeTime() + "]%" + message;
	return usrbuff;
}

std::string System::append2(std::string message, std::string usrbuff)
{
	usrbuff += "$^" + message;
	std::cout << usrbuff << std::endl;
	return usrbuff;
}

std::string System::changeTime() {
	std::ifstream inStream;
	inStream.open("sysTime");
	if(inStream.fail())
		std::cout << "HEY GETTIME FAILED!" << std::endl;
	int sysNum;
	std::cout << "SYS" << sysNum;
	inStream >> sysNum;
	std::ostringstream convert;
	std::string ret;
	convert << sysNum;
	ret = convert.str();
	inStream.close();
	
	std::ofstream outStream;
	outStream.open("sysTime");
	int newNum = ++sysNum;
	std::cout << newNum;
	outStream << newNum;
	outStream.close();
	return ret;
}



