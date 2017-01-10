#ifndef FILEHANDLE_H
#define FILEHANDLE_H

//#include <fstream>
#include <string>

class FileHandler
{
	private:

	public:
		FileHandler();
		void createUser(std::string name);
		std::string readUserBuffer(std::string name);
		std::string readUserTags(std::string name);
		bool writeUserBuffer(std::string name, std::string message);
				
};
#endif
