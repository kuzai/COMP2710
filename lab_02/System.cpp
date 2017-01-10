#include "System.h"
#include "Menu.h"
#include "WallPage.h"
#include "HomePage.h"
#include <iostream>

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
	getline(cin, newUser);
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
	HomePage homePages;
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
		/*case 0 : 
			//std::cout << "1" << std::endl;
			std::cout << "Enter Username: ";
			std::getline(std::cin, temp);
			createUser(temp);
			break;
		*/		
		case 1 :
			if(activeUser.getUsername().empty()) {
				std::cout << "You have to login to do that" << std::endl;
				break;	
			}
			//buffer.insert(0, postMessage());
			fHandler.writeUserBuffer(activeUser.getUsername(), postMessage());
			std::cout << buffer << std::endl;
			break;
		case 2 : 
			//WallPage wallPages();
			if(activeUser.getUsername().empty()) {
				std::cout << "You have to login to do that" << std::endl;
				break;	
			}
			wallPages.updateWall(activeUser, buffer, true);
			break;			
			//std::cout << "3" << std::endl;
		case 3 : 
			if(activeUser.getUsername().empty()) {
				std::cout << "You have to login to do that" << std::endl;
				break;	
			}
			homePages.updateHome(activeUser, buffer, true);
			break;			
			//std::cout << "4" << std::endl;
		case 4 : 
			std::cout << "Enter friend's name: ";
			std::getline(std::cin, temp);
			if(!checkUser(temp) || activeUser.checkFriends(temp)) {
				std::cout << "User does not exist or is already a friend!"<< std::endl;
				break;
			}
			else activeUser.addFriend(temp);//activeUser.addFriend(findUser(temp));
			break;			
			//std::cout << "5" << std::endl;
		case 5 :
			std::cout << "Enter Hash to follow: ";
			std::getline(std::cin, temp);
			if(activeUser.findHash(temp)) {
				std::cout << "Hash already followed!" << std::endl;
				break;
			}
			else activeUser.addHash(temp);
			break;
		/*
		case 6 :
			std::cout << "Enter Username: ";
			std::getline(std::cin, temp);
			if(!checkUser(temp)) {
				std::cout << "User doesn't exist" << std::endl;
				break; 
			}
			else login(findUser(temp));
			//std::cout << "7" << std::endl;
			break;
		*/
		case 7 : 
			keepRunning = false;
			break;
		default:
			std::cout << "Not a valid numerical option" << std::endl;	
	
	}
}


void System::createUser(std::string name) {
	if(checkUser(name))
	{
		std::cout << "User already exists!" << std::endl;
	}
	else {
	User user(name);
	userList.push_back(user);
	login(user);
	menu.newLogin(user.getUsername());
	fHandler.createUser(name);
	//std::cout << "hey I ran!!" + user.getUsername() << std::endl; 
	}
}

//set the active user of the system
void System::login(User user) {
	activeUser = user;
}


//Try to open the user file, if it isn't there then the user doesn't exist
bool System::checkUser(std::string name) {
	/*	
	for(std::vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (name == (*it).getUsername())
			return true;
	}
	*/
	std::ifstream inStream;
	inStream.open(name + ".txt");
	if(inStream.fail()) {
		inStream.close();
		return false;
	}
	return true;
}

User System::findUser(std::string name) {
	for(std::vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (name == (*it).getUsername())
			return (*it);
	}
	return User();
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
	usrbuff += "%[" + changeTime() + "]%" + message;
	return usrbuff;
}

std::string System::append2(std::string message, std::string usrbuff)
{
	usrbuff += "$^" + message;
	std::cout << usrbuff << std::endl;
	return usrbuff;
}

std::string changeTime() {
	std::ifstream inStream;
	inStream.open("sysTime");
	if(inStream.fail())
		std::cout << "HEY GETTIME FAILED!" << std::endl;
	std::string sysNum;
	std::getline(inStream, sysNum);
	inStream.close();
	std::ofstream outStream;
	outStream.open("sysTime");
	outStream << ++sysNum;
	outStream.close();
}


