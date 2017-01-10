#include "WallPage.h"
#include <iostream>

WallPage::WallPage(){
}

//if user is current user then print out the message
void WallPage::updateWall(User user, std::string buff, bool moreMessages) {
	std::cout << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "              " << user.getUsername() << "'s Wall" << std::endl;
	std::cout << "-------------------------------------" << std::endl; 
	std::cout << std::endl;
	std::string usrKey = "%[";
	std::string usrKey2 = "]%";
	std::string lineKey = "$^";
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
		//std::cout << usrMessage << std::endl;
		/*if(usrMessage != user.getUsername()) {
			//std::cout << "SHIT'S BROKE YO" << std::endl;
			continue;
		}
		
		else if(i == 3) {
			moreMessages = true;
		}
		*/
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
			updateWall(user, buff, !moreMessages);
		else if(res == "N" || res == "n");
		else std::cout << "invalid input, returning to menu." << std::endl;
		std::cout << std::endl;
	}
	//std::cout << "exiting here!!" << std::endl;
}
