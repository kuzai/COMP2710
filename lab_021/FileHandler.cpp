#include "FileHandler.h"
#include <fstream>
#include <iostream>

//create the filehandler
FileHandler::FileHandler() {

}

//creates the files for a new user
void FileHandler::createUser(std::string name) {
	std::ofstream outStream;
	outStream.open(name + ".txt");
	outStream.close();
	outStream.open(name + "_tags.txt");
	outStream.close();
}

std::string FileHandler::readUserBuffer(std::string name) {
	std::ifstream inStream;
	std::string buffer;
	inStream.open(name + ".txt");
	if(inStream.fail())
		return "";
	inStream >> buffer;
	//std::cout << buffer << " buffer!!!" << std::endl;
	inStream.close();
	return buffer;
}

bool FileHandler::writeUserBuffer(std::string name, std::string message) {
	std::ofstream outStream;
	std::string temp = readUserBuffer(name);
	temp.insert(0, message);
	//std::cout << temp << " temp!!" << std::endl;
	outStream.open(name + ".txt");
	outStream << temp;
	outStream.close();
}

