#include "HomePage.h"
#include <iostream>
#include <fstream>
HomePage::HomePage(FileHandler fHandle){
	userBuffer;
	fHandler = fHandle;
}


//Lots of things here. If user is friend or the user then print, else do lots of formatting for hashes
void HomePage::updateHome(User user, std::string buff, bool moreMessages) {
	std::cout << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "              " << user.getUsername() << "'s Home" << std::endl;
	std::cout << "-------------------------------------" << std::endl; 
	std::cout << std::endl;
	std::string usrKey = "%[";
	std::string usrKey2 = "]%";
	std::string lineKey = "$^";
	std::string hashKey = "#";
	std::string usrname;
	int delimiterLoc;
	int i = 0;
	//std::cout << "Loop starts now" << " this is buff: " << buff << std::endl;
	while((!buff.empty() && i < 3) || (!buff.empty() && !moreMessages))
	{
		std::cout << std::endl;
		std::string usrMessage = "";
		delimiterLoc = buff.find(usrKey);
		//std::cout << "delimiter LOC: " << delimiterLoc << std::endl;
		if(delimiterLoc == -1) {
			break;
		}
		//cout << "DELIMITER LOC RFIND: " << delimiterLoc << endl;
		//usrMessage = buff.substr(delimiterLoc + usrKey.length());
		buff.erase(0, delimiterLoc + usrKey.length());
		delimiterLoc = buff.find(usrKey2);
		usrMessage = buff.substr(0, delimiterLoc);
		usrname = usrMessage;
		//std::cout << usrMessage << std::endl;
		if(usrMessage != user.getUsername() && !user.checkFriends(usrMessage)) {
			int hashCheck = buff.find(hashKey);
			int delim2 = buff.find(usrKey);	
			bool moreHashes = true;
			bool addHashMsg = false;		
			std::string hashBuff = buff.substr(hashCheck + 1, delim2 - hashCheck - 1);
			std::string hashTemp;
			//std::cout << hashBuff << std::endl;
			//std::cout << user.findHash(hashBuff) << std::endl;
			if(user.findHash(hashBuff)) {
				moreHashes = false;
				addHashMsg = true;
			}
			while(!hashBuff.empty() && moreHashes) {
				int delimH, delimL;
				delimH = hashBuff.find(hashKey);
				delimL = hashBuff.find(lineKey);
				if(delimH != -1 && delimL == -1) {
					hashTemp = hashBuff.substr(0, delimH);
					hashBuff.erase(0, delimH + 1);
				}
				else if(delimL != -1 && delimH == -1) {
					hashTemp = hashBuff.substr(0, delimL);
					hashBuff.erase(0, delimL + 1);
					moreHashes = false;
				}
				else if(delimL != -1 && delimH != -1) {
					if(delimL < delimH) {
						hashTemp = hashBuff.substr(0, delimL);
						hashBuff.erase(0, delimH + 1);
					}
					else {
						hashTemp = hashBuff.substr(0, delimH);
						hashBuff.erase(0, delimH + 1);
					}
				}
				else {
					hashTemp = hashBuff;
					hashBuff.erase(0, hashBuff.length());
				}
				if(user.findHash(hashTemp)) {
					addHashMsg = true;
					break;
				}
			}
			if(!addHashMsg)
				continue;
		}
			std::cout << usrname << ">>" << std::endl;
			int pos = delimiterLoc + usrKey2.length();
			usrMessage = buff.substr(pos, buff.find(usrKey) - pos);
			while(!usrMessage.empty() && delimiterLoc != -1)
			{
				std::string messageOut = "";
				delimiterLoc = usrMessage.find(lineKey);
				//cout << "DELIMITER LOC FIND: " << delimiterLoc << endl;
				messageOut = usrMessage.substr(0, delimiterLoc);
				usrMessage.erase(0, delimiterLoc + lineKey.length());
				std::cout << messageOut << std::endl;
			}
			buff.erase(0, buff.find(usrKey));
			i++;
	}
	if(moreMessages) {
		std::cout << std::endl;
		std::cout << "Print more? (y/n): ";
		std::string res;
		std::getline(std::cin, res);
		if(res == "Y" || res == "y")
			updateHome(user, buff, !moreMessages);
		else if(res == "N" || res == "n");
		else std::cout << "invalid input, returning to menu." << std::endl;
		std::cout << std::endl;
	}
}
//deprecated
void HomePage::printHome(User user) {
	//print out the first three messages and check to see if more
}


void HomePage::userSort(User user) {
	struct SS {
		std::string buffer;
		std::string name;
	};
	std::vector<SS> usrs;
	std::ifstream iStream;
	iStream.open("userList.txt");
	std::string tmp;
	while(std::getline(iStream, tmp)) {
		SS s;
		s.name = tmp;
		s.buffer = fHandler.readUserBuffer(tmp);
		usrs.push_back(s);
	}
	SS w;
	std::string usrKey = "%[";
	std::string usrKey2 = "]%";
	std::string hashKey = "#";
	std::string lineKey = "$^";
	bool keepRun = true;
	while(keepRun) {
		keepRun = false;
		int greatest;
		for(std::vector<SS>::iterator it = usrs.begin(); it != usrs.end(); it++) {
			SS tmp = (*it);
			if(tmp.buffer.empty())
				continue;
			int delimiterLoc = tmp.buffer.find(usrKey);
			int delimiterLoc2 = tmp.buffer.find(usrKey2);
			if(delimiterLoc == -1) {
				continue;
			}
			keepRun = true;
			int pos = delimiterLoc + usrKey.length();
			std::string tstring = tmp.buffer.substr(pos, delimiterLoc2 - pos);
			if(std::stoi(tstring) > greatest)
				w = tmp;
		
		}
		
		//std::cout << w.name << ">>" << std::endl;
		int delimiterLoc = w.buffer.find(usrKey2);
		int delimiterLoc2 = w.buffer.find(usrKey);
		if(delimiterLoc == -1) {
			continue;
		}
		int pos = delimiterLoc + usrKey.length();
		std::string tstring = w.buffer.substr(pos, delimiterLoc2 - pos);
		
		if(user.checkFriends(w.name)) {
			std::cout << w.name << ">>" << std::endl;
			while(!tstring.empty() && delimiterLoc != -1)
			{
				std::string messageOut = "";
				delimiterLoc = tstring.find(lineKey);
				//cout << "DELIMITER LOC FIND: " << delimiterLoc << endl;
				messageOut = tstring.substr(0, delimiterLoc);
				tstring.erase(0, delimiterLoc + lineKey.length());
				std::cout << messageOut << std::endl;
			}
		}
		else {
			bool addHashMsg = false;
			std::vector<std::string> hashTmp = user.hashList;
			for(std::vector<std::string>::iterator it = hashTmp.begin(); it != hashTmp.end(); it++) {
				std::string n = (*it);
				if(w.buffer.find(n) != -1)
					addHashMsg = true;

			}
			
			if(!addHashMsg)
				continue;
			else {
				std::cout << w.name << ">>" << std::endl;
				while(!tstring.empty() && delimiterLoc != -1)
				{
					std::string messageOut = "";
					delimiterLoc = tstring.find(lineKey);
					//cout << "DELIMITER LOC FIND: " << delimiterLoc << endl;
					messageOut = tstring.substr(0, delimiterLoc);
					tstring.erase(0, delimiterLoc + lineKey.length());
					std::cout << messageOut << std::endl;
				}
				//i++;
			}
		}
	}

}
